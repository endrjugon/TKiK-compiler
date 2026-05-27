// Tiny single-connection HTTP server for the `pyrust --serve` web UI.
//
// Deliberately isolated from the ANTLR/generated headers: <windows.h> (pulled in
// by <winsock2.h>) defines macros such as ERROR and IN that collide with the
// generated enums, so the socket code lives in its own translation unit and
// only calls back into convertSource().

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#define NOGDI
#include <winsock2.h>
#include <ws2tcpip.h>
#ifdef ERROR
#undef ERROR
#endif
using socket_t = SOCKET;
#define CLOSESOCKET closesocket
#else
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
using socket_t = int;
#define INVALID_SOCKET (-1)
#define CLOSESOCKET ::close
#endif

#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>

// Defined in main.cpp.
bool convertSource(const std::string &source, std::string &out, std::string &err);

static const char *PAGE = R"HTML(<!doctype html>
<html lang="en">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>Python &#8594; Rust</title>
<style>
  :root { color-scheme: light dark; }
  * { box-sizing: border-box; }
  html, body { margin:0; height:100%; }
  body { font-family: system-ui, sans-serif; display:flex; flex-direction:column; height:100vh; }
  header { display:flex; gap:10px; align-items:center; flex-wrap:wrap;
           padding:10px 16px; background:#1f2933; color:#fff; }
  header h1 { font-size:16px; margin:0; font-weight:600; }
  .spacer { flex:1; }
  button, label.file { background:#3b82f6; color:#fff; border:0; padding:8px 14px;
           border-radius:6px; cursor:pointer; font-size:14px; }
  button:hover, label.file:hover { background:#2563eb; }
  .hint { font-size:12px; opacity:.7; }
  input[type=file] { display:none; }
  main { flex:1; display:flex; min-height:0; }
  .pane { flex:1; display:flex; flex-direction:column; min-width:0; border-right:1px solid #94a3b8; }
  .pane:last-child { border-right:0; }
  .pane h2 { margin:0; padding:6px 12px; font-size:12px; text-transform:uppercase;
             letter-spacing:.05em; background:#e5e7eb; color:#374151; }
  textarea { flex:1; border:0; padding:12px; resize:none; outline:none;
             font-family: ui-monospace, "Cascadia Code", Consolas, monospace;
             font-size:13px; white-space:pre; tab-size:4; }
  #out { background:#0b1021; color:#d6e2ff; }
  #status { padding:6px 16px; font-size:13px; background:#111827; color:#9ca3af;
            font-family: ui-monospace, monospace; white-space:pre-wrap; }
  #status.err { color:#fca5a5; } #status.ok { color:#86efac; }
</style>
</head>
<body>
<header>
  <h1>Python &#8594; Rust</h1>
  <label class="file">Open .py<input id="file" type="file" accept=".py"></label>
  <button id="convert">Convert &#8594;</button>
  <button id="save">Save .rs</button>
  <span class="spacer"></span>
  <span class="hint">Ctrl+Enter to convert</span>
</header>
<main>
  <section class="pane"><h2>Python</h2><textarea id="in" spellcheck="false"></textarea></section>
  <section class="pane"><h2>Rust</h2><textarea id="out" spellcheck="false" readonly></textarea></section>
</main>
<div id="status">Ready.</div>
<script>
const $ = id => document.getElementById(id);
$('in').value = `x = 5
print(x)
x = "now a string"
print(x)

def add(a, b):
    return a + b

print(add(2, 3))
print([i * i for i in range(5)])
`;
async function convert() {
  const s = $('status'); s.className = ''; s.textContent = 'Converting...';
  try {
    const res = await fetch('/convert', { method:'POST', body: $('in').value });
    const text = await res.text();
    $('out').value = text;
    if (res.ok) { s.className = 'ok'; s.textContent = 'OK - converted.'; }
    else { s.className = 'err'; s.textContent = 'Syntax error:\n' + text; }
  } catch (e) { s.className = 'err'; s.textContent = 'Server error: ' + e; }
}
$('convert').onclick = convert;
$('file').onchange = e => {
  const f = e.target.files[0]; if (!f) return;
  const r = new FileReader(); r.onload = () => { $('in').value = r.result; }; r.readAsText(f);
};
$('save').onclick = () => {
  const blob = new Blob([$('out').value], { type:'text/plain' });
  const a = document.createElement('a');
  a.href = URL.createObjectURL(blob); a.download = 'output.rs'; a.click();
};
$('in').addEventListener('keydown', e => {
  if ((e.ctrlKey || e.metaKey) && e.key === 'Enter') { e.preventDefault(); convert(); }
});
</script>
</body>
</html>)HTML";

static void sendAll(socket_t c, const std::string &data) {
    size_t sent = 0;
    while (sent < data.size()) {
        int n = (int)send(c, data.data() + sent, (int)(data.size() - sent), 0);
        if (n <= 0) break;
        sent += (size_t)n;
    }
}

static void sendResponse(socket_t c, const std::string &status,
                         const std::string &ctype, const std::string &body) {
    std::string r = "HTTP/1.1 " + status + "\r\n";
    r += "Content-Type: " + ctype + "\r\n";
    r += "Content-Length: " + std::to_string(body.size()) + "\r\n";
    r += "Connection: close\r\n\r\n";
    r += body;
    sendAll(c, r);
}

static void handleConnection(socket_t c) {
    std::string data;
    char buf[8192];
    size_t headerEnd = std::string::npos;
    while ((headerEnd = data.find("\r\n\r\n")) == std::string::npos) {
        int n = (int)recv(c, buf, sizeof(buf), 0);
        if (n <= 0) return;
        data.append(buf, (size_t)n);
        if (data.size() > (1u << 24)) return;  // 16 MB guard
    }
    std::string head = data.substr(0, headerEnd);
    std::string lower = head;
    for (char &ch : lower) ch = (char)std::tolower((unsigned char)ch);

    size_t contentLen = 0;
    auto clp = lower.find("content-length:");
    if (clp != std::string::npos)
        contentLen = (size_t)std::strtoul(head.c_str() + clp + 15, nullptr, 10);

    size_t bodyStart = headerEnd + 4;
    while (data.size() - bodyStart < contentLen) {
        int n = (int)recv(c, buf, sizeof(buf), 0);
        if (n <= 0) break;
        data.append(buf, (size_t)n);
    }
    std::string body = data.substr(bodyStart, contentLen);

    std::string method = head.substr(0, head.find(' '));
    size_t p1 = head.find(' ');
    size_t p2 = head.find(' ', p1 + 1);
    std::string path = head.substr(p1 + 1, p2 - p1 - 1);

    if (method == "GET" && (path == "/" || path == "/index.html")) {
        sendResponse(c, "200 OK", "text/html; charset=utf-8", PAGE);
    } else if (method == "POST" && path == "/convert") {
        std::string rust, err;
        if (convertSource(body, rust, err))
            sendResponse(c, "200 OK", "text/plain; charset=utf-8", rust);
        else
            sendResponse(c, "400 Bad Request", "text/plain; charset=utf-8", err);
    } else {
        sendResponse(c, "404 Not Found", "text/plain", "Not found");
    }
}

int runServer(int port) {
#ifdef _WIN32
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        std::cerr << "WSAStartup failed\n";
        return 1;
    }
#endif
    socket_t s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == INVALID_SOCKET) { std::cerr << "socket() failed\n"; return 1; }
    int opt = 1;
    setsockopt(s, SOL_SOCKET, SO_REUSEADDR, (const char *)&opt, sizeof(opt));

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons((unsigned short)port);
    if (bind(s, (sockaddr *)&addr, sizeof(addr)) != 0) {
        std::cerr << "bind() failed on port " << port << "\n";
        return 1;
    }
    listen(s, 16);
    std::cerr << "pyrust web UI: open http://127.0.0.1:" << port
              << "  (Ctrl+C to stop)\n";
    for (;;) {
        socket_t c = accept(s, nullptr, nullptr);
        if (c == INVALID_SOCKET) continue;
        handleConnection(c);
        CLOSESOCKET(c);
    }
}
