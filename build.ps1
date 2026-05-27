# Build script for the Python -> Rust converter (pyrust).
#
# Requirements on PATH:
#   * java   (to run the ANTLR generator)
#   * g++    (MinGW-w64 / MSYS2, C++17)
#   * ar     (binutils, ships with MinGW)
#
# Usage:
#   ./build.ps1            # generate parser, build runtime if needed, build pyrust
#   ./build.ps1 -Regen     # force re-running the ANTLR generator
#   ./build.ps1 -Clean     # remove build artifacts first

param(
    [switch]$Regen,
    [switch]$Clean
)

$ErrorActionPreference = "Stop"
$root    = $PSScriptRoot
$jar     = Join-Path $root "third_party/antlr-4.13.2-complete.jar"
$grammar = Join-Path $root "grammar"
$gen     = Join-Path $root "src/generated"
$rtSrc   = Join-Path $root "third_party/antlr4-cpp-runtime/runtime/src"
$build   = Join-Path $root "build"
$lib     = Join-Path $build "libantlr4-runtime.a"
$exe     = Join-Path $build "pyrust.exe"

$cxxflags = @("-std=c++17", "-O2", "-DANTLR4CPP_STATIC")

if ($Clean) {
    Write-Host "Cleaning build artifacts..."
    Remove-Item -Recurse -Force $build, $gen -ErrorAction SilentlyContinue
}
New-Item -ItemType Directory -Force -Path $build | Out-Null

# 1. Generate the C++ lexer/parser/visitor from the grammars.
if ($Regen -or -not (Test-Path (Join-Path $gen "PythonRustParser.cpp"))) {
    Write-Host "Generating parser with ANTLR..."
    & java -jar $jar -Dlanguage=Cpp -visitor -no-listener -o $gen -Xexact-output-dir `
        (Join-Path $grammar "PythonRustLexer.g4") (Join-Path $grammar "PythonRustParser.g4")
    if ($LASTEXITCODE -ne 0) { throw "ANTLR generation failed" }
}

# 2. Build the ANTLR4 C++ runtime into a static library (only once; it is slow).
if (-not (Test-Path $lib)) {
    Write-Host "Building ANTLR4 C++ runtime (one-time, this takes a few minutes)..."
    $objDir = Join-Path $build "rt_obj"
    New-Item -ItemType Directory -Force -Path $objDir | Out-Null
    $objs = @()
    foreach ($f in Get-ChildItem -Path $rtSrc -Recurse -Filter *.cpp) {
        $rel = $f.FullName.Substring($rtSrc.Length + 1)
        $obj = Join-Path $objDir (($rel -replace '[\\/.]', '_') + ".o")
        & g++ @cxxflags "-I$rtSrc" -c $f.FullName -o $obj
        if ($LASTEXITCODE -ne 0) { throw "Failed to compile runtime file: $rel" }
        $objs += $obj
    }
    & ar rcs $lib $objs
    if ($LASTEXITCODE -ne 0) { throw "Failed to archive runtime library" }
}

# 3. Compile and link the converter (static so it has no DLL dependencies).
Write-Host "Building pyrust.exe..."
$srcs = @(
    (Join-Path $root "src/main.cpp"),
    (Join-Path $root "src/webserver.cpp"),
    (Join-Path $root "src/PythonLexerBase.cpp"),
    (Join-Path $gen  "PythonRustLexer.cpp"),
    (Join-Path $gen  "PythonRustParser.cpp"),
    (Join-Path $gen  "PythonRustParserBaseVisitor.cpp"),
    (Join-Path $gen  "PythonRustParserVisitor.cpp")
)
# -lws2_32 provides Winsock for the `--serve` web UI.
& g++ @cxxflags "-I$rtSrc" "-I$(Join-Path $root 'src')" "-I$gen" `
    $srcs $lib -static -static-libgcc -static-libstdc++ -lws2_32 -o $exe
if ($LASTEXITCODE -ne 0) { throw "Failed to build pyrust.exe" }

Write-Host "Done: $exe"
