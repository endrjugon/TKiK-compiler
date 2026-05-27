
// Generated from grammar/PythonRustParser.g4 by ANTLR 4.13.2


#include "PythonRustParserVisitor.h"

#include "PythonRustParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct PythonRustParserStaticData final {
  PythonRustParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  PythonRustParserStaticData(const PythonRustParserStaticData&) = delete;
  PythonRustParserStaticData(PythonRustParserStaticData&&) = delete;
  PythonRustParserStaticData& operator=(const PythonRustParserStaticData&) = delete;
  PythonRustParserStaticData& operator=(PythonRustParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag pythonrustparserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<PythonRustParserStaticData> pythonrustparserParserStaticData = nullptr;

void pythonrustparserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (pythonrustparserParserStaticData != nullptr) {
    return;
  }
#else
  assert(pythonrustparserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<PythonRustParserStaticData>(
    std::vector<std::string>{
      "program", "stmt", "simple_stmt", "small_stmt", "expr_stmt", "annassign", 
      "return_stmt", "import_stmt", "import_list", "dotted_name", "raise_stmt", 
      "pass_stmt", "flow_stmt", "compound_stmt", "if_stmt", "while_stmt", 
      "for_stmt", "try_stmt", "except_clause", "funcdef", "classdef", "suite", 
      "parameters", "param", "arglist", "argument", "target_list", "target", 
      "testlist", "type", "expr", "subscript", "slice", "atom", "list_maker", 
      "set_or_dict", "dict_kv", "comp_clause"
    },
    std::vector<std::string>{
      "", "", "", "'def'", "'return'", "'if'", "'elif'", "'else'", "'while'", 
      "'for'", "'in'", "'break'", "'continue'", "'pass'", "'try'", "'except'", 
      "'finally'", "'raise'", "'class'", "'import'", "'from'", "'as'", "'True'", 
      "'False'", "'None'", "'and'", "'or'", "'not'", "'->'", "'+'", "'-'", 
      "'*'", "'/'", "'%'", "'=='", "'!='", "'<='", "'>='", "'='", "'<'", 
      "'>'", "'('", "')'", "'['", "']'", "'{'", "'}'", "':'", "','", "'.'"
    },
    std::vector<std::string>{
      "", "INDENT", "DEDENT", "DEF", "RETURN", "IF", "ELIF", "ELSE", "WHILE", 
      "FOR", "IN", "BREAK", "CONTINUE", "PASS", "TRY", "EXCEPT", "FINALLY", 
      "RAISE", "CLASS", "IMPORT", "FROM", "AS", "TRUE", "FALSE", "NONE", 
      "AND", "OR", "NOT", "ARROW", "PLUS", "MINUS", "STAR", "DIV", "MOD", 
      "EQ", "NEQ", "LE", "GE", "ASSIGN", "LT", "GT", "LPAREN", "RPAREN", 
      "LBRACK", "RBRACK", "LBRACE", "RBRACE", "COLON", "COMMA", "DOT", "FLOAT", 
      "INT", "STRING", "ID", "NEWLINE", "LINE_JOIN", "WS", "COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,57,522,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,1,0,1,0,5,0,79,8,0,10,0,12,0,82,9,0,1,0,1,0,1,
  	1,1,1,3,1,88,8,1,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,3,3,99,8,3,1,4,1,
  	4,1,4,1,4,5,4,105,8,4,10,4,12,4,108,9,4,3,4,110,8,4,1,5,1,5,1,5,1,5,3,
  	5,116,8,5,1,6,1,6,3,6,120,8,6,1,7,1,7,1,7,1,7,3,7,126,8,7,1,7,1,7,1,7,
  	1,7,1,7,3,7,133,8,7,1,8,1,8,1,8,1,8,3,8,139,8,8,1,8,1,8,1,8,1,8,3,8,145,
  	8,8,5,8,147,8,8,10,8,12,8,150,9,8,3,8,152,8,8,1,9,1,9,1,9,5,9,157,8,9,
  	10,9,12,9,160,9,9,1,10,1,10,1,10,1,10,3,10,166,8,10,3,10,168,8,10,1,11,
  	1,11,1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,13,3,13,180,8,13,1,14,1,14,
  	1,14,1,14,1,14,1,14,1,14,1,14,1,14,5,14,191,8,14,10,14,12,14,194,9,14,
  	1,14,1,14,1,14,3,14,199,8,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,3,15,
  	208,8,15,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,3,16,219,8,16,1,
  	17,1,17,1,17,1,17,1,17,1,17,1,17,4,17,228,8,17,11,17,12,17,229,1,17,1,
  	17,1,17,3,17,235,8,17,1,17,1,17,1,17,3,17,240,8,17,1,17,1,17,1,17,3,17,
  	245,8,17,1,18,1,18,1,18,1,18,3,18,251,8,18,3,18,253,8,18,1,19,1,19,1,
  	19,1,19,3,19,259,8,19,1,19,1,19,1,19,3,19,264,8,19,1,19,1,19,1,19,1,20,
  	1,20,1,20,1,20,3,20,273,8,20,1,20,3,20,276,8,20,1,20,1,20,1,20,1,21,1,
  	21,1,21,1,21,4,21,285,8,21,11,21,12,21,286,1,21,1,21,3,21,291,8,21,1,
  	22,1,22,1,22,5,22,296,8,22,10,22,12,22,299,9,22,1,22,3,22,302,8,22,1,
  	23,1,23,1,23,3,23,307,8,23,1,23,1,23,3,23,311,8,23,1,24,1,24,1,24,5,24,
  	316,8,24,10,24,12,24,319,9,24,1,24,3,24,322,8,24,1,25,1,25,1,25,1,25,
  	3,25,328,8,25,1,26,1,26,1,26,5,26,333,8,26,10,26,12,26,336,9,26,1,26,
  	3,26,339,8,26,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,3,27,350,8,
  	27,1,28,1,28,1,28,5,28,355,8,28,10,28,12,28,358,9,28,1,28,3,28,361,8,
  	28,1,29,1,29,1,29,1,29,1,29,5,29,368,8,29,10,29,12,29,371,9,29,1,29,1,
  	29,3,29,375,8,29,1,29,3,29,378,8,29,1,30,1,30,1,30,1,30,1,30,1,30,3,30,
  	386,8,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,
  	1,30,1,30,1,30,1,30,1,30,1,30,3,30,406,8,30,1,30,1,30,1,30,1,30,1,30,
  	1,30,1,30,1,30,1,30,5,30,417,8,30,10,30,12,30,420,9,30,1,31,1,31,3,31,
  	424,8,31,1,32,3,32,427,8,32,1,32,1,32,3,32,431,8,32,1,32,1,32,3,32,435,
  	8,32,3,32,437,8,32,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,
  	1,33,3,33,450,8,33,1,33,3,33,453,8,33,1,34,1,34,1,34,1,34,1,34,1,34,1,
  	34,5,34,462,8,34,10,34,12,34,465,9,34,1,34,3,34,468,8,34,3,34,470,8,34,
  	1,34,1,34,1,35,1,35,1,35,1,35,1,35,1,35,1,35,5,35,481,8,35,10,35,12,35,
  	484,9,35,1,35,3,35,487,8,35,1,35,1,35,1,35,1,35,1,35,1,35,5,35,495,8,
  	35,10,35,12,35,498,9,35,1,35,3,35,501,8,35,3,35,503,8,35,1,35,1,35,1,
  	36,1,36,1,36,1,36,1,37,1,37,1,37,1,37,1,37,1,37,3,37,517,8,37,1,37,3,
  	37,520,8,37,1,37,0,1,60,38,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,
  	32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,0,4,
  	1,0,11,12,1,0,29,30,1,0,31,33,2,0,34,37,39,40,581,0,80,1,0,0,0,2,87,1,
  	0,0,0,4,89,1,0,0,0,6,98,1,0,0,0,8,100,1,0,0,0,10,111,1,0,0,0,12,117,1,
  	0,0,0,14,132,1,0,0,0,16,151,1,0,0,0,18,153,1,0,0,0,20,161,1,0,0,0,22,
  	169,1,0,0,0,24,171,1,0,0,0,26,179,1,0,0,0,28,181,1,0,0,0,30,200,1,0,0,
  	0,32,209,1,0,0,0,34,220,1,0,0,0,36,246,1,0,0,0,38,254,1,0,0,0,40,268,
  	1,0,0,0,42,290,1,0,0,0,44,292,1,0,0,0,46,303,1,0,0,0,48,312,1,0,0,0,50,
  	327,1,0,0,0,52,329,1,0,0,0,54,349,1,0,0,0,56,351,1,0,0,0,58,377,1,0,0,
  	0,60,385,1,0,0,0,62,423,1,0,0,0,64,426,1,0,0,0,66,452,1,0,0,0,68,454,
  	1,0,0,0,70,473,1,0,0,0,72,506,1,0,0,0,74,510,1,0,0,0,76,79,5,54,0,0,77,
  	79,3,2,1,0,78,76,1,0,0,0,78,77,1,0,0,0,79,82,1,0,0,0,80,78,1,0,0,0,80,
  	81,1,0,0,0,81,83,1,0,0,0,82,80,1,0,0,0,83,84,5,0,0,1,84,1,1,0,0,0,85,
  	88,3,4,2,0,86,88,3,26,13,0,87,85,1,0,0,0,87,86,1,0,0,0,88,3,1,0,0,0,89,
  	90,3,6,3,0,90,91,5,54,0,0,91,5,1,0,0,0,92,99,3,8,4,0,93,99,3,12,6,0,94,
  	99,3,14,7,0,95,99,3,20,10,0,96,99,3,22,11,0,97,99,3,24,12,0,98,92,1,0,
  	0,0,98,93,1,0,0,0,98,94,1,0,0,0,98,95,1,0,0,0,98,96,1,0,0,0,98,97,1,0,
  	0,0,99,7,1,0,0,0,100,109,3,56,28,0,101,110,3,10,5,0,102,103,5,38,0,0,
  	103,105,3,56,28,0,104,102,1,0,0,0,105,108,1,0,0,0,106,104,1,0,0,0,106,
  	107,1,0,0,0,107,110,1,0,0,0,108,106,1,0,0,0,109,101,1,0,0,0,109,106,1,
  	0,0,0,110,9,1,0,0,0,111,112,5,47,0,0,112,115,3,58,29,0,113,114,5,38,0,
  	0,114,116,3,56,28,0,115,113,1,0,0,0,115,116,1,0,0,0,116,11,1,0,0,0,117,
  	119,5,4,0,0,118,120,3,56,28,0,119,118,1,0,0,0,119,120,1,0,0,0,120,13,
  	1,0,0,0,121,122,5,19,0,0,122,125,3,18,9,0,123,124,5,21,0,0,124,126,5,
  	53,0,0,125,123,1,0,0,0,125,126,1,0,0,0,126,133,1,0,0,0,127,128,5,20,0,
  	0,128,129,3,18,9,0,129,130,5,19,0,0,130,131,3,16,8,0,131,133,1,0,0,0,
  	132,121,1,0,0,0,132,127,1,0,0,0,133,15,1,0,0,0,134,152,5,31,0,0,135,138,
  	5,53,0,0,136,137,5,21,0,0,137,139,5,53,0,0,138,136,1,0,0,0,138,139,1,
  	0,0,0,139,148,1,0,0,0,140,141,5,48,0,0,141,144,5,53,0,0,142,143,5,21,
  	0,0,143,145,5,53,0,0,144,142,1,0,0,0,144,145,1,0,0,0,145,147,1,0,0,0,
  	146,140,1,0,0,0,147,150,1,0,0,0,148,146,1,0,0,0,148,149,1,0,0,0,149,152,
  	1,0,0,0,150,148,1,0,0,0,151,134,1,0,0,0,151,135,1,0,0,0,152,17,1,0,0,
  	0,153,158,5,53,0,0,154,155,5,49,0,0,155,157,5,53,0,0,156,154,1,0,0,0,
  	157,160,1,0,0,0,158,156,1,0,0,0,158,159,1,0,0,0,159,19,1,0,0,0,160,158,
  	1,0,0,0,161,167,5,17,0,0,162,165,3,60,30,0,163,164,5,20,0,0,164,166,3,
  	60,30,0,165,163,1,0,0,0,165,166,1,0,0,0,166,168,1,0,0,0,167,162,1,0,0,
  	0,167,168,1,0,0,0,168,21,1,0,0,0,169,170,5,13,0,0,170,23,1,0,0,0,171,
  	172,7,0,0,0,172,25,1,0,0,0,173,180,3,28,14,0,174,180,3,30,15,0,175,180,
  	3,32,16,0,176,180,3,34,17,0,177,180,3,38,19,0,178,180,3,40,20,0,179,173,
  	1,0,0,0,179,174,1,0,0,0,179,175,1,0,0,0,179,176,1,0,0,0,179,177,1,0,0,
  	0,179,178,1,0,0,0,180,27,1,0,0,0,181,182,5,5,0,0,182,183,3,60,30,0,183,
  	184,5,47,0,0,184,192,3,42,21,0,185,186,5,6,0,0,186,187,3,60,30,0,187,
  	188,5,47,0,0,188,189,3,42,21,0,189,191,1,0,0,0,190,185,1,0,0,0,191,194,
  	1,0,0,0,192,190,1,0,0,0,192,193,1,0,0,0,193,198,1,0,0,0,194,192,1,0,0,
  	0,195,196,5,7,0,0,196,197,5,47,0,0,197,199,3,42,21,0,198,195,1,0,0,0,
  	198,199,1,0,0,0,199,29,1,0,0,0,200,201,5,8,0,0,201,202,3,60,30,0,202,
  	203,5,47,0,0,203,207,3,42,21,0,204,205,5,7,0,0,205,206,5,47,0,0,206,208,
  	3,42,21,0,207,204,1,0,0,0,207,208,1,0,0,0,208,31,1,0,0,0,209,210,5,9,
  	0,0,210,211,3,52,26,0,211,212,5,10,0,0,212,213,3,56,28,0,213,214,5,47,
  	0,0,214,218,3,42,21,0,215,216,5,7,0,0,216,217,5,47,0,0,217,219,3,42,21,
  	0,218,215,1,0,0,0,218,219,1,0,0,0,219,33,1,0,0,0,220,221,5,14,0,0,221,
  	222,5,47,0,0,222,244,3,42,21,0,223,224,3,36,18,0,224,225,5,47,0,0,225,
  	226,3,42,21,0,226,228,1,0,0,0,227,223,1,0,0,0,228,229,1,0,0,0,229,227,
  	1,0,0,0,229,230,1,0,0,0,230,234,1,0,0,0,231,232,5,7,0,0,232,233,5,47,
  	0,0,233,235,3,42,21,0,234,231,1,0,0,0,234,235,1,0,0,0,235,239,1,0,0,0,
  	236,237,5,16,0,0,237,238,5,47,0,0,238,240,3,42,21,0,239,236,1,0,0,0,239,
  	240,1,0,0,0,240,245,1,0,0,0,241,242,5,16,0,0,242,243,5,47,0,0,243,245,
  	3,42,21,0,244,227,1,0,0,0,244,241,1,0,0,0,245,35,1,0,0,0,246,252,5,15,
  	0,0,247,250,3,60,30,0,248,249,5,21,0,0,249,251,5,53,0,0,250,248,1,0,0,
  	0,250,251,1,0,0,0,251,253,1,0,0,0,252,247,1,0,0,0,252,253,1,0,0,0,253,
  	37,1,0,0,0,254,255,5,3,0,0,255,256,5,53,0,0,256,258,5,41,0,0,257,259,
  	3,44,22,0,258,257,1,0,0,0,258,259,1,0,0,0,259,260,1,0,0,0,260,263,5,42,
  	0,0,261,262,5,28,0,0,262,264,3,58,29,0,263,261,1,0,0,0,263,264,1,0,0,
  	0,264,265,1,0,0,0,265,266,5,47,0,0,266,267,3,42,21,0,267,39,1,0,0,0,268,
  	269,5,18,0,0,269,275,5,53,0,0,270,272,5,41,0,0,271,273,3,48,24,0,272,
  	271,1,0,0,0,272,273,1,0,0,0,273,274,1,0,0,0,274,276,5,42,0,0,275,270,
  	1,0,0,0,275,276,1,0,0,0,276,277,1,0,0,0,277,278,5,47,0,0,278,279,3,42,
  	21,0,279,41,1,0,0,0,280,291,3,4,2,0,281,282,5,54,0,0,282,284,5,1,0,0,
  	283,285,3,2,1,0,284,283,1,0,0,0,285,286,1,0,0,0,286,284,1,0,0,0,286,287,
  	1,0,0,0,287,288,1,0,0,0,288,289,5,2,0,0,289,291,1,0,0,0,290,280,1,0,0,
  	0,290,281,1,0,0,0,291,43,1,0,0,0,292,297,3,46,23,0,293,294,5,48,0,0,294,
  	296,3,46,23,0,295,293,1,0,0,0,296,299,1,0,0,0,297,295,1,0,0,0,297,298,
  	1,0,0,0,298,301,1,0,0,0,299,297,1,0,0,0,300,302,5,48,0,0,301,300,1,0,
  	0,0,301,302,1,0,0,0,302,45,1,0,0,0,303,306,5,53,0,0,304,305,5,47,0,0,
  	305,307,3,58,29,0,306,304,1,0,0,0,306,307,1,0,0,0,307,310,1,0,0,0,308,
  	309,5,38,0,0,309,311,3,60,30,0,310,308,1,0,0,0,310,311,1,0,0,0,311,47,
  	1,0,0,0,312,317,3,50,25,0,313,314,5,48,0,0,314,316,3,50,25,0,315,313,
  	1,0,0,0,316,319,1,0,0,0,317,315,1,0,0,0,317,318,1,0,0,0,318,321,1,0,0,
  	0,319,317,1,0,0,0,320,322,5,48,0,0,321,320,1,0,0,0,321,322,1,0,0,0,322,
  	49,1,0,0,0,323,324,5,53,0,0,324,325,5,38,0,0,325,328,3,60,30,0,326,328,
  	3,60,30,0,327,323,1,0,0,0,327,326,1,0,0,0,328,51,1,0,0,0,329,334,3,54,
  	27,0,330,331,5,48,0,0,331,333,3,54,27,0,332,330,1,0,0,0,333,336,1,0,0,
  	0,334,332,1,0,0,0,334,335,1,0,0,0,335,338,1,0,0,0,336,334,1,0,0,0,337,
  	339,5,48,0,0,338,337,1,0,0,0,338,339,1,0,0,0,339,53,1,0,0,0,340,350,5,
  	53,0,0,341,342,5,41,0,0,342,343,3,52,26,0,343,344,5,42,0,0,344,350,1,
  	0,0,0,345,346,5,43,0,0,346,347,3,52,26,0,347,348,5,44,0,0,348,350,1,0,
  	0,0,349,340,1,0,0,0,349,341,1,0,0,0,349,345,1,0,0,0,350,55,1,0,0,0,351,
  	356,3,60,30,0,352,353,5,48,0,0,353,355,3,60,30,0,354,352,1,0,0,0,355,
  	358,1,0,0,0,356,354,1,0,0,0,356,357,1,0,0,0,357,360,1,0,0,0,358,356,1,
  	0,0,0,359,361,5,48,0,0,360,359,1,0,0,0,360,361,1,0,0,0,361,57,1,0,0,0,
  	362,374,5,53,0,0,363,364,5,43,0,0,364,369,3,58,29,0,365,366,5,48,0,0,
  	366,368,3,58,29,0,367,365,1,0,0,0,368,371,1,0,0,0,369,367,1,0,0,0,369,
  	370,1,0,0,0,370,372,1,0,0,0,371,369,1,0,0,0,372,373,5,44,0,0,373,375,
  	1,0,0,0,374,363,1,0,0,0,374,375,1,0,0,0,375,378,1,0,0,0,376,378,5,24,
  	0,0,377,362,1,0,0,0,377,376,1,0,0,0,378,59,1,0,0,0,379,380,6,30,-1,0,
  	380,381,7,1,0,0,381,386,3,60,30,8,382,383,5,27,0,0,383,386,3,60,30,4,
  	384,386,3,66,33,0,385,379,1,0,0,0,385,382,1,0,0,0,385,384,1,0,0,0,386,
  	418,1,0,0,0,387,388,10,7,0,0,388,389,7,2,0,0,389,417,3,60,30,8,390,391,
  	10,6,0,0,391,392,7,1,0,0,392,417,3,60,30,7,393,394,10,5,0,0,394,395,7,
  	3,0,0,395,417,3,60,30,6,396,397,10,3,0,0,397,398,5,25,0,0,398,417,3,60,
  	30,4,399,400,10,2,0,0,400,401,5,26,0,0,401,417,3,60,30,3,402,403,10,11,
  	0,0,403,405,5,41,0,0,404,406,3,48,24,0,405,404,1,0,0,0,405,406,1,0,0,
  	0,406,407,1,0,0,0,407,417,5,42,0,0,408,409,10,10,0,0,409,410,5,43,0,0,
  	410,411,3,62,31,0,411,412,5,44,0,0,412,417,1,0,0,0,413,414,10,9,0,0,414,
  	415,5,49,0,0,415,417,5,53,0,0,416,387,1,0,0,0,416,390,1,0,0,0,416,393,
  	1,0,0,0,416,396,1,0,0,0,416,399,1,0,0,0,416,402,1,0,0,0,416,408,1,0,0,
  	0,416,413,1,0,0,0,417,420,1,0,0,0,418,416,1,0,0,0,418,419,1,0,0,0,419,
  	61,1,0,0,0,420,418,1,0,0,0,421,424,3,64,32,0,422,424,3,60,30,0,423,421,
  	1,0,0,0,423,422,1,0,0,0,424,63,1,0,0,0,425,427,3,60,30,0,426,425,1,0,
  	0,0,426,427,1,0,0,0,427,428,1,0,0,0,428,430,5,47,0,0,429,431,3,60,30,
  	0,430,429,1,0,0,0,430,431,1,0,0,0,431,436,1,0,0,0,432,434,5,47,0,0,433,
  	435,3,60,30,0,434,433,1,0,0,0,434,435,1,0,0,0,435,437,1,0,0,0,436,432,
  	1,0,0,0,436,437,1,0,0,0,437,65,1,0,0,0,438,453,5,51,0,0,439,453,5,50,
  	0,0,440,453,5,52,0,0,441,453,5,22,0,0,442,453,5,23,0,0,443,453,5,24,0,
  	0,444,453,5,53,0,0,445,453,3,68,34,0,446,453,3,70,35,0,447,449,5,41,0,
  	0,448,450,3,56,28,0,449,448,1,0,0,0,449,450,1,0,0,0,450,451,1,0,0,0,451,
  	453,5,42,0,0,452,438,1,0,0,0,452,439,1,0,0,0,452,440,1,0,0,0,452,441,
  	1,0,0,0,452,442,1,0,0,0,452,443,1,0,0,0,452,444,1,0,0,0,452,445,1,0,0,
  	0,452,446,1,0,0,0,452,447,1,0,0,0,453,67,1,0,0,0,454,469,5,43,0,0,455,
  	456,3,60,30,0,456,457,3,74,37,0,457,470,1,0,0,0,458,463,3,60,30,0,459,
  	460,5,48,0,0,460,462,3,60,30,0,461,459,1,0,0,0,462,465,1,0,0,0,463,461,
  	1,0,0,0,463,464,1,0,0,0,464,467,1,0,0,0,465,463,1,0,0,0,466,468,5,48,
  	0,0,467,466,1,0,0,0,467,468,1,0,0,0,468,470,1,0,0,0,469,455,1,0,0,0,469,
  	458,1,0,0,0,469,470,1,0,0,0,470,471,1,0,0,0,471,472,5,44,0,0,472,69,1,
  	0,0,0,473,502,5,45,0,0,474,475,3,72,36,0,475,476,3,74,37,0,476,503,1,
  	0,0,0,477,482,3,72,36,0,478,479,5,48,0,0,479,481,3,72,36,0,480,478,1,
  	0,0,0,481,484,1,0,0,0,482,480,1,0,0,0,482,483,1,0,0,0,483,486,1,0,0,0,
  	484,482,1,0,0,0,485,487,5,48,0,0,486,485,1,0,0,0,486,487,1,0,0,0,487,
  	503,1,0,0,0,488,489,3,60,30,0,489,490,3,74,37,0,490,503,1,0,0,0,491,496,
  	3,60,30,0,492,493,5,48,0,0,493,495,3,60,30,0,494,492,1,0,0,0,495,498,
  	1,0,0,0,496,494,1,0,0,0,496,497,1,0,0,0,497,500,1,0,0,0,498,496,1,0,0,
  	0,499,501,5,48,0,0,500,499,1,0,0,0,500,501,1,0,0,0,501,503,1,0,0,0,502,
  	474,1,0,0,0,502,477,1,0,0,0,502,488,1,0,0,0,502,491,1,0,0,0,502,503,1,
  	0,0,0,503,504,1,0,0,0,504,505,5,46,0,0,505,71,1,0,0,0,506,507,3,60,30,
  	0,507,508,5,47,0,0,508,509,3,60,30,0,509,73,1,0,0,0,510,511,5,9,0,0,511,
  	512,3,52,26,0,512,513,5,10,0,0,513,516,3,60,30,0,514,515,5,5,0,0,515,
  	517,3,60,30,0,516,514,1,0,0,0,516,517,1,0,0,0,517,519,1,0,0,0,518,520,
  	3,74,37,0,519,518,1,0,0,0,519,520,1,0,0,0,520,75,1,0,0,0,70,78,80,87,
  	98,106,109,115,119,125,132,138,144,148,151,158,165,167,179,192,198,207,
  	218,229,234,239,244,250,252,258,263,272,275,286,290,297,301,306,310,317,
  	321,327,334,338,349,356,360,369,374,377,385,405,416,418,423,426,430,434,
  	436,449,452,463,467,469,482,486,496,500,502,516,519
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  pythonrustparserParserStaticData = std::move(staticData);
}

}

PythonRustParser::PythonRustParser(TokenStream *input) : PythonRustParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

PythonRustParser::PythonRustParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  PythonRustParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *pythonrustparserParserStaticData->atn, pythonrustparserParserStaticData->decisionToDFA, pythonrustparserParserStaticData->sharedContextCache, options);
}

PythonRustParser::~PythonRustParser() {
  delete _interpreter;
}

const atn::ATN& PythonRustParser::getATN() const {
  return *pythonrustparserParserStaticData->atn;
}

std::string PythonRustParser::getGrammarFileName() const {
  return "PythonRustParser.g4";
}

const std::vector<std::string>& PythonRustParser::getRuleNames() const {
  return pythonrustparserParserStaticData->ruleNames;
}

const dfa::Vocabulary& PythonRustParser::getVocabulary() const {
  return pythonrustparserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView PythonRustParser::getSerializedATN() const {
  return pythonrustparserParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

PythonRustParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PythonRustParser::ProgramContext::EOF() {
  return getToken(PythonRustParser::EOF, 0);
}

std::vector<tree::TerminalNode *> PythonRustParser::ProgramContext::NEWLINE() {
  return getTokens(PythonRustParser::NEWLINE);
}

tree::TerminalNode* PythonRustParser::ProgramContext::NEWLINE(size_t i) {
  return getToken(PythonRustParser::NEWLINE, i);
}

std::vector<PythonRustParser::StmtContext *> PythonRustParser::ProgramContext::stmt() {
  return getRuleContexts<PythonRustParser::StmtContext>();
}

PythonRustParser::StmtContext* PythonRustParser::ProgramContext::stmt(size_t i) {
  return getRuleContext<PythonRustParser::StmtContext>(i);
}


size_t PythonRustParser::ProgramContext::getRuleIndex() const {
  return PythonRustParser::RuleProgram;
}


std::any PythonRustParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::ProgramContext* PythonRustParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, PythonRustParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(80);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 34949078376676152) != 0)) {
      setState(78);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case PythonRustParser::NEWLINE: {
          setState(76);
          match(PythonRustParser::NEWLINE);
          break;
        }

        case PythonRustParser::DEF:
        case PythonRustParser::RETURN:
        case PythonRustParser::IF:
        case PythonRustParser::WHILE:
        case PythonRustParser::FOR:
        case PythonRustParser::BREAK:
        case PythonRustParser::CONTINUE:
        case PythonRustParser::PASS:
        case PythonRustParser::TRY:
        case PythonRustParser::RAISE:
        case PythonRustParser::CLASS:
        case PythonRustParser::IMPORT:
        case PythonRustParser::FROM:
        case PythonRustParser::TRUE:
        case PythonRustParser::FALSE:
        case PythonRustParser::NONE:
        case PythonRustParser::NOT:
        case PythonRustParser::PLUS:
        case PythonRustParser::MINUS:
        case PythonRustParser::LPAREN:
        case PythonRustParser::LBRACK:
        case PythonRustParser::LBRACE:
        case PythonRustParser::FLOAT:
        case PythonRustParser::INT:
        case PythonRustParser::STRING:
        case PythonRustParser::ID: {
          setState(77);
          stmt();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(82);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(83);
    match(PythonRustParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

PythonRustParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PythonRustParser::Simple_stmtContext* PythonRustParser::StmtContext::simple_stmt() {
  return getRuleContext<PythonRustParser::Simple_stmtContext>(0);
}

PythonRustParser::Compound_stmtContext* PythonRustParser::StmtContext::compound_stmt() {
  return getRuleContext<PythonRustParser::Compound_stmtContext>(0);
}


size_t PythonRustParser::StmtContext::getRuleIndex() const {
  return PythonRustParser::RuleStmt;
}


std::any PythonRustParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::StmtContext* PythonRustParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 2, PythonRustParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(87);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PythonRustParser::RETURN:
      case PythonRustParser::BREAK:
      case PythonRustParser::CONTINUE:
      case PythonRustParser::PASS:
      case PythonRustParser::RAISE:
      case PythonRustParser::IMPORT:
      case PythonRustParser::FROM:
      case PythonRustParser::TRUE:
      case PythonRustParser::FALSE:
      case PythonRustParser::NONE:
      case PythonRustParser::NOT:
      case PythonRustParser::PLUS:
      case PythonRustParser::MINUS:
      case PythonRustParser::LPAREN:
      case PythonRustParser::LBRACK:
      case PythonRustParser::LBRACE:
      case PythonRustParser::FLOAT:
      case PythonRustParser::INT:
      case PythonRustParser::STRING:
      case PythonRustParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(85);
        simple_stmt();
        break;
      }

      case PythonRustParser::DEF:
      case PythonRustParser::IF:
      case PythonRustParser::WHILE:
      case PythonRustParser::FOR:
      case PythonRustParser::TRY:
      case PythonRustParser::CLASS: {
        enterOuterAlt(_localctx, 2);
        setState(86);
        compound_stmt();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_stmtContext ------------------------------------------------------------------

PythonRustParser::Simple_stmtContext::Simple_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PythonRustParser::Small_stmtContext* PythonRustParser::Simple_stmtContext::small_stmt() {
  return getRuleContext<PythonRustParser::Small_stmtContext>(0);
}

tree::TerminalNode* PythonRustParser::Simple_stmtContext::NEWLINE() {
  return getToken(PythonRustParser::NEWLINE, 0);
}


size_t PythonRustParser::Simple_stmtContext::getRuleIndex() const {
  return PythonRustParser::RuleSimple_stmt;
}


std::any PythonRustParser::Simple_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitSimple_stmt(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::Simple_stmtContext* PythonRustParser::simple_stmt() {
  Simple_stmtContext *_localctx = _tracker.createInstance<Simple_stmtContext>(_ctx, getState());
  enterRule(_localctx, 4, PythonRustParser::RuleSimple_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(89);
    small_stmt();
    setState(90);
    match(PythonRustParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Small_stmtContext ------------------------------------------------------------------

PythonRustParser::Small_stmtContext::Small_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PythonRustParser::Expr_stmtContext* PythonRustParser::Small_stmtContext::expr_stmt() {
  return getRuleContext<PythonRustParser::Expr_stmtContext>(0);
}

PythonRustParser::Return_stmtContext* PythonRustParser::Small_stmtContext::return_stmt() {
  return getRuleContext<PythonRustParser::Return_stmtContext>(0);
}

PythonRustParser::Import_stmtContext* PythonRustParser::Small_stmtContext::import_stmt() {
  return getRuleContext<PythonRustParser::Import_stmtContext>(0);
}

PythonRustParser::Raise_stmtContext* PythonRustParser::Small_stmtContext::raise_stmt() {
  return getRuleContext<PythonRustParser::Raise_stmtContext>(0);
}

PythonRustParser::Pass_stmtContext* PythonRustParser::Small_stmtContext::pass_stmt() {
  return getRuleContext<PythonRustParser::Pass_stmtContext>(0);
}

PythonRustParser::Flow_stmtContext* PythonRustParser::Small_stmtContext::flow_stmt() {
  return getRuleContext<PythonRustParser::Flow_stmtContext>(0);
}


size_t PythonRustParser::Small_stmtContext::getRuleIndex() const {
  return PythonRustParser::RuleSmall_stmt;
}


std::any PythonRustParser::Small_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitSmall_stmt(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::Small_stmtContext* PythonRustParser::small_stmt() {
  Small_stmtContext *_localctx = _tracker.createInstance<Small_stmtContext>(_ctx, getState());
  enterRule(_localctx, 6, PythonRustParser::RuleSmall_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(98);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PythonRustParser::TRUE:
      case PythonRustParser::FALSE:
      case PythonRustParser::NONE:
      case PythonRustParser::NOT:
      case PythonRustParser::PLUS:
      case PythonRustParser::MINUS:
      case PythonRustParser::LPAREN:
      case PythonRustParser::LBRACK:
      case PythonRustParser::LBRACE:
      case PythonRustParser::FLOAT:
      case PythonRustParser::INT:
      case PythonRustParser::STRING:
      case PythonRustParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(92);
        expr_stmt();
        break;
      }

      case PythonRustParser::RETURN: {
        enterOuterAlt(_localctx, 2);
        setState(93);
        return_stmt();
        break;
      }

      case PythonRustParser::IMPORT:
      case PythonRustParser::FROM: {
        enterOuterAlt(_localctx, 3);
        setState(94);
        import_stmt();
        break;
      }

      case PythonRustParser::RAISE: {
        enterOuterAlt(_localctx, 4);
        setState(95);
        raise_stmt();
        break;
      }

      case PythonRustParser::PASS: {
        enterOuterAlt(_localctx, 5);
        setState(96);
        pass_stmt();
        break;
      }

      case PythonRustParser::BREAK:
      case PythonRustParser::CONTINUE: {
        enterOuterAlt(_localctx, 6);
        setState(97);
        flow_stmt();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr_stmtContext ------------------------------------------------------------------

PythonRustParser::Expr_stmtContext::Expr_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PythonRustParser::TestlistContext *> PythonRustParser::Expr_stmtContext::testlist() {
  return getRuleContexts<PythonRustParser::TestlistContext>();
}

PythonRustParser::TestlistContext* PythonRustParser::Expr_stmtContext::testlist(size_t i) {
  return getRuleContext<PythonRustParser::TestlistContext>(i);
}

PythonRustParser::AnnassignContext* PythonRustParser::Expr_stmtContext::annassign() {
  return getRuleContext<PythonRustParser::AnnassignContext>(0);
}

std::vector<tree::TerminalNode *> PythonRustParser::Expr_stmtContext::ASSIGN() {
  return getTokens(PythonRustParser::ASSIGN);
}

tree::TerminalNode* PythonRustParser::Expr_stmtContext::ASSIGN(size_t i) {
  return getToken(PythonRustParser::ASSIGN, i);
}


size_t PythonRustParser::Expr_stmtContext::getRuleIndex() const {
  return PythonRustParser::RuleExpr_stmt;
}


std::any PythonRustParser::Expr_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitExpr_stmt(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::Expr_stmtContext* PythonRustParser::expr_stmt() {
  Expr_stmtContext *_localctx = _tracker.createInstance<Expr_stmtContext>(_ctx, getState());
  enterRule(_localctx, 8, PythonRustParser::RuleExpr_stmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(100);
    testlist();
    setState(109);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PythonRustParser::COLON: {
        setState(101);
        annassign();
        break;
      }

      case PythonRustParser::ASSIGN:
      case PythonRustParser::NEWLINE: {
        setState(106);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PythonRustParser::ASSIGN) {
          setState(102);
          match(PythonRustParser::ASSIGN);
          setState(103);
          testlist();
          setState(108);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnnassignContext ------------------------------------------------------------------

PythonRustParser::AnnassignContext::AnnassignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PythonRustParser::AnnassignContext::COLON() {
  return getToken(PythonRustParser::COLON, 0);
}

PythonRustParser::TypeContext* PythonRustParser::AnnassignContext::type() {
  return getRuleContext<PythonRustParser::TypeContext>(0);
}

tree::TerminalNode* PythonRustParser::AnnassignContext::ASSIGN() {
  return getToken(PythonRustParser::ASSIGN, 0);
}

PythonRustParser::TestlistContext* PythonRustParser::AnnassignContext::testlist() {
  return getRuleContext<PythonRustParser::TestlistContext>(0);
}


size_t PythonRustParser::AnnassignContext::getRuleIndex() const {
  return PythonRustParser::RuleAnnassign;
}


std::any PythonRustParser::AnnassignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitAnnassign(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::AnnassignContext* PythonRustParser::annassign() {
  AnnassignContext *_localctx = _tracker.createInstance<AnnassignContext>(_ctx, getState());
  enterRule(_localctx, 10, PythonRustParser::RuleAnnassign);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(111);
    match(PythonRustParser::COLON);
    setState(112);
    type();
    setState(115);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PythonRustParser::ASSIGN) {
      setState(113);
      match(PythonRustParser::ASSIGN);
      setState(114);
      testlist();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Return_stmtContext ------------------------------------------------------------------

PythonRustParser::Return_stmtContext::Return_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PythonRustParser::Return_stmtContext::RETURN() {
  return getToken(PythonRustParser::RETURN, 0);
}

PythonRustParser::TestlistContext* PythonRustParser::Return_stmtContext::testlist() {
  return getRuleContext<PythonRustParser::TestlistContext>(0);
}


size_t PythonRustParser::Return_stmtContext::getRuleIndex() const {
  return PythonRustParser::RuleReturn_stmt;
}


std::any PythonRustParser::Return_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitReturn_stmt(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::Return_stmtContext* PythonRustParser::return_stmt() {
  Return_stmtContext *_localctx = _tracker.createInstance<Return_stmtContext>(_ctx, getState());
  enterRule(_localctx, 12, PythonRustParser::RuleReturn_stmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(117);
    match(PythonRustParser::RETURN);
    setState(119);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 16934679865196544) != 0)) {
      setState(118);
      testlist();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Import_stmtContext ------------------------------------------------------------------

PythonRustParser::Import_stmtContext::Import_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PythonRustParser::Import_stmtContext::IMPORT() {
  return getToken(PythonRustParser::IMPORT, 0);
}

PythonRustParser::Dotted_nameContext* PythonRustParser::Import_stmtContext::dotted_name() {
  return getRuleContext<PythonRustParser::Dotted_nameContext>(0);
}

tree::TerminalNode* PythonRustParser::Import_stmtContext::AS() {
  return getToken(PythonRustParser::AS, 0);
}

tree::TerminalNode* PythonRustParser::Import_stmtContext::ID() {
  return getToken(PythonRustParser::ID, 0);
}

tree::TerminalNode* PythonRustParser::Import_stmtContext::FROM() {
  return getToken(PythonRustParser::FROM, 0);
}

PythonRustParser::Import_listContext* PythonRustParser::Import_stmtContext::import_list() {
  return getRuleContext<PythonRustParser::Import_listContext>(0);
}


size_t PythonRustParser::Import_stmtContext::getRuleIndex() const {
  return PythonRustParser::RuleImport_stmt;
}


std::any PythonRustParser::Import_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitImport_stmt(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::Import_stmtContext* PythonRustParser::import_stmt() {
  Import_stmtContext *_localctx = _tracker.createInstance<Import_stmtContext>(_ctx, getState());
  enterRule(_localctx, 14, PythonRustParser::RuleImport_stmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(132);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PythonRustParser::IMPORT: {
        enterOuterAlt(_localctx, 1);
        setState(121);
        match(PythonRustParser::IMPORT);
        setState(122);
        dotted_name();
        setState(125);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PythonRustParser::AS) {
          setState(123);
          match(PythonRustParser::AS);
          setState(124);
          match(PythonRustParser::ID);
        }
        break;
      }

      case PythonRustParser::FROM: {
        enterOuterAlt(_localctx, 2);
        setState(127);
        match(PythonRustParser::FROM);
        setState(128);
        dotted_name();
        setState(129);
        match(PythonRustParser::IMPORT);
        setState(130);
        import_list();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Import_listContext ------------------------------------------------------------------

PythonRustParser::Import_listContext::Import_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PythonRustParser::Import_listContext::STAR() {
  return getToken(PythonRustParser::STAR, 0);
}

std::vector<tree::TerminalNode *> PythonRustParser::Import_listContext::ID() {
  return getTokens(PythonRustParser::ID);
}

tree::TerminalNode* PythonRustParser::Import_listContext::ID(size_t i) {
  return getToken(PythonRustParser::ID, i);
}

std::vector<tree::TerminalNode *> PythonRustParser::Import_listContext::AS() {
  return getTokens(PythonRustParser::AS);
}

tree::TerminalNode* PythonRustParser::Import_listContext::AS(size_t i) {
  return getToken(PythonRustParser::AS, i);
}

std::vector<tree::TerminalNode *> PythonRustParser::Import_listContext::COMMA() {
  return getTokens(PythonRustParser::COMMA);
}

tree::TerminalNode* PythonRustParser::Import_listContext::COMMA(size_t i) {
  return getToken(PythonRustParser::COMMA, i);
}


size_t PythonRustParser::Import_listContext::getRuleIndex() const {
  return PythonRustParser::RuleImport_list;
}


std::any PythonRustParser::Import_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitImport_list(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::Import_listContext* PythonRustParser::import_list() {
  Import_listContext *_localctx = _tracker.createInstance<Import_listContext>(_ctx, getState());
  enterRule(_localctx, 16, PythonRustParser::RuleImport_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(151);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PythonRustParser::STAR: {
        enterOuterAlt(_localctx, 1);
        setState(134);
        match(PythonRustParser::STAR);
        break;
      }

      case PythonRustParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(135);
        match(PythonRustParser::ID);
        setState(138);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PythonRustParser::AS) {
          setState(136);
          match(PythonRustParser::AS);
          setState(137);
          match(PythonRustParser::ID);
        }
        setState(148);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PythonRustParser::COMMA) {
          setState(140);
          match(PythonRustParser::COMMA);
          setState(141);
          match(PythonRustParser::ID);
          setState(144);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == PythonRustParser::AS) {
            setState(142);
            match(PythonRustParser::AS);
            setState(143);
            match(PythonRustParser::ID);
          }
          setState(150);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Dotted_nameContext ------------------------------------------------------------------

PythonRustParser::Dotted_nameContext::Dotted_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> PythonRustParser::Dotted_nameContext::ID() {
  return getTokens(PythonRustParser::ID);
}

tree::TerminalNode* PythonRustParser::Dotted_nameContext::ID(size_t i) {
  return getToken(PythonRustParser::ID, i);
}

std::vector<tree::TerminalNode *> PythonRustParser::Dotted_nameContext::DOT() {
  return getTokens(PythonRustParser::DOT);
}

tree::TerminalNode* PythonRustParser::Dotted_nameContext::DOT(size_t i) {
  return getToken(PythonRustParser::DOT, i);
}


size_t PythonRustParser::Dotted_nameContext::getRuleIndex() const {
  return PythonRustParser::RuleDotted_name;
}


std::any PythonRustParser::Dotted_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitDotted_name(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::Dotted_nameContext* PythonRustParser::dotted_name() {
  Dotted_nameContext *_localctx = _tracker.createInstance<Dotted_nameContext>(_ctx, getState());
  enterRule(_localctx, 18, PythonRustParser::RuleDotted_name);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(153);
    match(PythonRustParser::ID);
    setState(158);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PythonRustParser::DOT) {
      setState(154);
      match(PythonRustParser::DOT);
      setState(155);
      match(PythonRustParser::ID);
      setState(160);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Raise_stmtContext ------------------------------------------------------------------

PythonRustParser::Raise_stmtContext::Raise_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PythonRustParser::Raise_stmtContext::RAISE() {
  return getToken(PythonRustParser::RAISE, 0);
}

std::vector<PythonRustParser::ExprContext *> PythonRustParser::Raise_stmtContext::expr() {
  return getRuleContexts<PythonRustParser::ExprContext>();
}

PythonRustParser::ExprContext* PythonRustParser::Raise_stmtContext::expr(size_t i) {
  return getRuleContext<PythonRustParser::ExprContext>(i);
}

tree::TerminalNode* PythonRustParser::Raise_stmtContext::FROM() {
  return getToken(PythonRustParser::FROM, 0);
}


size_t PythonRustParser::Raise_stmtContext::getRuleIndex() const {
  return PythonRustParser::RuleRaise_stmt;
}


std::any PythonRustParser::Raise_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitRaise_stmt(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::Raise_stmtContext* PythonRustParser::raise_stmt() {
  Raise_stmtContext *_localctx = _tracker.createInstance<Raise_stmtContext>(_ctx, getState());
  enterRule(_localctx, 20, PythonRustParser::RuleRaise_stmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(161);
    match(PythonRustParser::RAISE);
    setState(167);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 16934679865196544) != 0)) {
      setState(162);
      expr(0);
      setState(165);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PythonRustParser::FROM) {
        setState(163);
        match(PythonRustParser::FROM);
        setState(164);
        expr(0);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Pass_stmtContext ------------------------------------------------------------------

PythonRustParser::Pass_stmtContext::Pass_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PythonRustParser::Pass_stmtContext::PASS() {
  return getToken(PythonRustParser::PASS, 0);
}


size_t PythonRustParser::Pass_stmtContext::getRuleIndex() const {
  return PythonRustParser::RulePass_stmt;
}


std::any PythonRustParser::Pass_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitPass_stmt(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::Pass_stmtContext* PythonRustParser::pass_stmt() {
  Pass_stmtContext *_localctx = _tracker.createInstance<Pass_stmtContext>(_ctx, getState());
  enterRule(_localctx, 22, PythonRustParser::RulePass_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(169);
    match(PythonRustParser::PASS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Flow_stmtContext ------------------------------------------------------------------

PythonRustParser::Flow_stmtContext::Flow_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PythonRustParser::Flow_stmtContext::BREAK() {
  return getToken(PythonRustParser::BREAK, 0);
}

tree::TerminalNode* PythonRustParser::Flow_stmtContext::CONTINUE() {
  return getToken(PythonRustParser::CONTINUE, 0);
}


size_t PythonRustParser::Flow_stmtContext::getRuleIndex() const {
  return PythonRustParser::RuleFlow_stmt;
}


std::any PythonRustParser::Flow_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitFlow_stmt(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::Flow_stmtContext* PythonRustParser::flow_stmt() {
  Flow_stmtContext *_localctx = _tracker.createInstance<Flow_stmtContext>(_ctx, getState());
  enterRule(_localctx, 24, PythonRustParser::RuleFlow_stmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(171);
    _la = _input->LA(1);
    if (!(_la == PythonRustParser::BREAK

    || _la == PythonRustParser::CONTINUE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Compound_stmtContext ------------------------------------------------------------------

PythonRustParser::Compound_stmtContext::Compound_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PythonRustParser::If_stmtContext* PythonRustParser::Compound_stmtContext::if_stmt() {
  return getRuleContext<PythonRustParser::If_stmtContext>(0);
}

PythonRustParser::While_stmtContext* PythonRustParser::Compound_stmtContext::while_stmt() {
  return getRuleContext<PythonRustParser::While_stmtContext>(0);
}

PythonRustParser::For_stmtContext* PythonRustParser::Compound_stmtContext::for_stmt() {
  return getRuleContext<PythonRustParser::For_stmtContext>(0);
}

PythonRustParser::Try_stmtContext* PythonRustParser::Compound_stmtContext::try_stmt() {
  return getRuleContext<PythonRustParser::Try_stmtContext>(0);
}

PythonRustParser::FuncdefContext* PythonRustParser::Compound_stmtContext::funcdef() {
  return getRuleContext<PythonRustParser::FuncdefContext>(0);
}

PythonRustParser::ClassdefContext* PythonRustParser::Compound_stmtContext::classdef() {
  return getRuleContext<PythonRustParser::ClassdefContext>(0);
}


size_t PythonRustParser::Compound_stmtContext::getRuleIndex() const {
  return PythonRustParser::RuleCompound_stmt;
}


std::any PythonRustParser::Compound_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitCompound_stmt(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::Compound_stmtContext* PythonRustParser::compound_stmt() {
  Compound_stmtContext *_localctx = _tracker.createInstance<Compound_stmtContext>(_ctx, getState());
  enterRule(_localctx, 26, PythonRustParser::RuleCompound_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(179);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PythonRustParser::IF: {
        enterOuterAlt(_localctx, 1);
        setState(173);
        if_stmt();
        break;
      }

      case PythonRustParser::WHILE: {
        enterOuterAlt(_localctx, 2);
        setState(174);
        while_stmt();
        break;
      }

      case PythonRustParser::FOR: {
        enterOuterAlt(_localctx, 3);
        setState(175);
        for_stmt();
        break;
      }

      case PythonRustParser::TRY: {
        enterOuterAlt(_localctx, 4);
        setState(176);
        try_stmt();
        break;
      }

      case PythonRustParser::DEF: {
        enterOuterAlt(_localctx, 5);
        setState(177);
        funcdef();
        break;
      }

      case PythonRustParser::CLASS: {
        enterOuterAlt(_localctx, 6);
        setState(178);
        classdef();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_stmtContext ------------------------------------------------------------------

PythonRustParser::If_stmtContext::If_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PythonRustParser::If_stmtContext::IF() {
  return getToken(PythonRustParser::IF, 0);
}

std::vector<PythonRustParser::ExprContext *> PythonRustParser::If_stmtContext::expr() {
  return getRuleContexts<PythonRustParser::ExprContext>();
}

PythonRustParser::ExprContext* PythonRustParser::If_stmtContext::expr(size_t i) {
  return getRuleContext<PythonRustParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> PythonRustParser::If_stmtContext::COLON() {
  return getTokens(PythonRustParser::COLON);
}

tree::TerminalNode* PythonRustParser::If_stmtContext::COLON(size_t i) {
  return getToken(PythonRustParser::COLON, i);
}

std::vector<PythonRustParser::SuiteContext *> PythonRustParser::If_stmtContext::suite() {
  return getRuleContexts<PythonRustParser::SuiteContext>();
}

PythonRustParser::SuiteContext* PythonRustParser::If_stmtContext::suite(size_t i) {
  return getRuleContext<PythonRustParser::SuiteContext>(i);
}

std::vector<tree::TerminalNode *> PythonRustParser::If_stmtContext::ELIF() {
  return getTokens(PythonRustParser::ELIF);
}

tree::TerminalNode* PythonRustParser::If_stmtContext::ELIF(size_t i) {
  return getToken(PythonRustParser::ELIF, i);
}

tree::TerminalNode* PythonRustParser::If_stmtContext::ELSE() {
  return getToken(PythonRustParser::ELSE, 0);
}


size_t PythonRustParser::If_stmtContext::getRuleIndex() const {
  return PythonRustParser::RuleIf_stmt;
}


std::any PythonRustParser::If_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitIf_stmt(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::If_stmtContext* PythonRustParser::if_stmt() {
  If_stmtContext *_localctx = _tracker.createInstance<If_stmtContext>(_ctx, getState());
  enterRule(_localctx, 28, PythonRustParser::RuleIf_stmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(181);
    match(PythonRustParser::IF);
    setState(182);
    expr(0);
    setState(183);
    match(PythonRustParser::COLON);
    setState(184);
    suite();
    setState(192);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PythonRustParser::ELIF) {
      setState(185);
      match(PythonRustParser::ELIF);
      setState(186);
      expr(0);
      setState(187);
      match(PythonRustParser::COLON);
      setState(188);
      suite();
      setState(194);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(198);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PythonRustParser::ELSE) {
      setState(195);
      match(PythonRustParser::ELSE);
      setState(196);
      match(PythonRustParser::COLON);
      setState(197);
      suite();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- While_stmtContext ------------------------------------------------------------------

PythonRustParser::While_stmtContext::While_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PythonRustParser::While_stmtContext::WHILE() {
  return getToken(PythonRustParser::WHILE, 0);
}

PythonRustParser::ExprContext* PythonRustParser::While_stmtContext::expr() {
  return getRuleContext<PythonRustParser::ExprContext>(0);
}

std::vector<tree::TerminalNode *> PythonRustParser::While_stmtContext::COLON() {
  return getTokens(PythonRustParser::COLON);
}

tree::TerminalNode* PythonRustParser::While_stmtContext::COLON(size_t i) {
  return getToken(PythonRustParser::COLON, i);
}

std::vector<PythonRustParser::SuiteContext *> PythonRustParser::While_stmtContext::suite() {
  return getRuleContexts<PythonRustParser::SuiteContext>();
}

PythonRustParser::SuiteContext* PythonRustParser::While_stmtContext::suite(size_t i) {
  return getRuleContext<PythonRustParser::SuiteContext>(i);
}

tree::TerminalNode* PythonRustParser::While_stmtContext::ELSE() {
  return getToken(PythonRustParser::ELSE, 0);
}


size_t PythonRustParser::While_stmtContext::getRuleIndex() const {
  return PythonRustParser::RuleWhile_stmt;
}


std::any PythonRustParser::While_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitWhile_stmt(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::While_stmtContext* PythonRustParser::while_stmt() {
  While_stmtContext *_localctx = _tracker.createInstance<While_stmtContext>(_ctx, getState());
  enterRule(_localctx, 30, PythonRustParser::RuleWhile_stmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(200);
    match(PythonRustParser::WHILE);
    setState(201);
    expr(0);
    setState(202);
    match(PythonRustParser::COLON);
    setState(203);
    suite();
    setState(207);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PythonRustParser::ELSE) {
      setState(204);
      match(PythonRustParser::ELSE);
      setState(205);
      match(PythonRustParser::COLON);
      setState(206);
      suite();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For_stmtContext ------------------------------------------------------------------

PythonRustParser::For_stmtContext::For_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PythonRustParser::For_stmtContext::FOR() {
  return getToken(PythonRustParser::FOR, 0);
}

PythonRustParser::Target_listContext* PythonRustParser::For_stmtContext::target_list() {
  return getRuleContext<PythonRustParser::Target_listContext>(0);
}

tree::TerminalNode* PythonRustParser::For_stmtContext::IN() {
  return getToken(PythonRustParser::IN, 0);
}

PythonRustParser::TestlistContext* PythonRustParser::For_stmtContext::testlist() {
  return getRuleContext<PythonRustParser::TestlistContext>(0);
}

std::vector<tree::TerminalNode *> PythonRustParser::For_stmtContext::COLON() {
  return getTokens(PythonRustParser::COLON);
}

tree::TerminalNode* PythonRustParser::For_stmtContext::COLON(size_t i) {
  return getToken(PythonRustParser::COLON, i);
}

std::vector<PythonRustParser::SuiteContext *> PythonRustParser::For_stmtContext::suite() {
  return getRuleContexts<PythonRustParser::SuiteContext>();
}

PythonRustParser::SuiteContext* PythonRustParser::For_stmtContext::suite(size_t i) {
  return getRuleContext<PythonRustParser::SuiteContext>(i);
}

tree::TerminalNode* PythonRustParser::For_stmtContext::ELSE() {
  return getToken(PythonRustParser::ELSE, 0);
}


size_t PythonRustParser::For_stmtContext::getRuleIndex() const {
  return PythonRustParser::RuleFor_stmt;
}


std::any PythonRustParser::For_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitFor_stmt(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::For_stmtContext* PythonRustParser::for_stmt() {
  For_stmtContext *_localctx = _tracker.createInstance<For_stmtContext>(_ctx, getState());
  enterRule(_localctx, 32, PythonRustParser::RuleFor_stmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(209);
    match(PythonRustParser::FOR);
    setState(210);
    target_list();
    setState(211);
    match(PythonRustParser::IN);
    setState(212);
    testlist();
    setState(213);
    match(PythonRustParser::COLON);
    setState(214);
    suite();
    setState(218);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PythonRustParser::ELSE) {
      setState(215);
      match(PythonRustParser::ELSE);
      setState(216);
      match(PythonRustParser::COLON);
      setState(217);
      suite();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Try_stmtContext ------------------------------------------------------------------

PythonRustParser::Try_stmtContext::Try_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PythonRustParser::Try_stmtContext::TRY() {
  return getToken(PythonRustParser::TRY, 0);
}

std::vector<tree::TerminalNode *> PythonRustParser::Try_stmtContext::COLON() {
  return getTokens(PythonRustParser::COLON);
}

tree::TerminalNode* PythonRustParser::Try_stmtContext::COLON(size_t i) {
  return getToken(PythonRustParser::COLON, i);
}

std::vector<PythonRustParser::SuiteContext *> PythonRustParser::Try_stmtContext::suite() {
  return getRuleContexts<PythonRustParser::SuiteContext>();
}

PythonRustParser::SuiteContext* PythonRustParser::Try_stmtContext::suite(size_t i) {
  return getRuleContext<PythonRustParser::SuiteContext>(i);
}

tree::TerminalNode* PythonRustParser::Try_stmtContext::FINALLY() {
  return getToken(PythonRustParser::FINALLY, 0);
}

std::vector<PythonRustParser::Except_clauseContext *> PythonRustParser::Try_stmtContext::except_clause() {
  return getRuleContexts<PythonRustParser::Except_clauseContext>();
}

PythonRustParser::Except_clauseContext* PythonRustParser::Try_stmtContext::except_clause(size_t i) {
  return getRuleContext<PythonRustParser::Except_clauseContext>(i);
}

tree::TerminalNode* PythonRustParser::Try_stmtContext::ELSE() {
  return getToken(PythonRustParser::ELSE, 0);
}


size_t PythonRustParser::Try_stmtContext::getRuleIndex() const {
  return PythonRustParser::RuleTry_stmt;
}


std::any PythonRustParser::Try_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitTry_stmt(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::Try_stmtContext* PythonRustParser::try_stmt() {
  Try_stmtContext *_localctx = _tracker.createInstance<Try_stmtContext>(_ctx, getState());
  enterRule(_localctx, 34, PythonRustParser::RuleTry_stmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(220);
    match(PythonRustParser::TRY);
    setState(221);
    match(PythonRustParser::COLON);
    setState(222);
    suite();
    setState(244);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PythonRustParser::EXCEPT: {
        setState(227); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(223);
          except_clause();
          setState(224);
          match(PythonRustParser::COLON);
          setState(225);
          suite();
          setState(229); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == PythonRustParser::EXCEPT);
        setState(234);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PythonRustParser::ELSE) {
          setState(231);
          match(PythonRustParser::ELSE);
          setState(232);
          match(PythonRustParser::COLON);
          setState(233);
          suite();
        }
        setState(239);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PythonRustParser::FINALLY) {
          setState(236);
          match(PythonRustParser::FINALLY);
          setState(237);
          match(PythonRustParser::COLON);
          setState(238);
          suite();
        }
        break;
      }

      case PythonRustParser::FINALLY: {
        setState(241);
        match(PythonRustParser::FINALLY);
        setState(242);
        match(PythonRustParser::COLON);
        setState(243);
        suite();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Except_clauseContext ------------------------------------------------------------------

PythonRustParser::Except_clauseContext::Except_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PythonRustParser::Except_clauseContext::EXCEPT() {
  return getToken(PythonRustParser::EXCEPT, 0);
}

PythonRustParser::ExprContext* PythonRustParser::Except_clauseContext::expr() {
  return getRuleContext<PythonRustParser::ExprContext>(0);
}

tree::TerminalNode* PythonRustParser::Except_clauseContext::AS() {
  return getToken(PythonRustParser::AS, 0);
}

tree::TerminalNode* PythonRustParser::Except_clauseContext::ID() {
  return getToken(PythonRustParser::ID, 0);
}


size_t PythonRustParser::Except_clauseContext::getRuleIndex() const {
  return PythonRustParser::RuleExcept_clause;
}


std::any PythonRustParser::Except_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitExcept_clause(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::Except_clauseContext* PythonRustParser::except_clause() {
  Except_clauseContext *_localctx = _tracker.createInstance<Except_clauseContext>(_ctx, getState());
  enterRule(_localctx, 36, PythonRustParser::RuleExcept_clause);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(246);
    match(PythonRustParser::EXCEPT);
    setState(252);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 16934679865196544) != 0)) {
      setState(247);
      expr(0);
      setState(250);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PythonRustParser::AS) {
        setState(248);
        match(PythonRustParser::AS);
        setState(249);
        match(PythonRustParser::ID);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncdefContext ------------------------------------------------------------------

PythonRustParser::FuncdefContext::FuncdefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PythonRustParser::FuncdefContext::DEF() {
  return getToken(PythonRustParser::DEF, 0);
}

tree::TerminalNode* PythonRustParser::FuncdefContext::ID() {
  return getToken(PythonRustParser::ID, 0);
}

tree::TerminalNode* PythonRustParser::FuncdefContext::LPAREN() {
  return getToken(PythonRustParser::LPAREN, 0);
}

tree::TerminalNode* PythonRustParser::FuncdefContext::RPAREN() {
  return getToken(PythonRustParser::RPAREN, 0);
}

tree::TerminalNode* PythonRustParser::FuncdefContext::COLON() {
  return getToken(PythonRustParser::COLON, 0);
}

PythonRustParser::SuiteContext* PythonRustParser::FuncdefContext::suite() {
  return getRuleContext<PythonRustParser::SuiteContext>(0);
}

PythonRustParser::ParametersContext* PythonRustParser::FuncdefContext::parameters() {
  return getRuleContext<PythonRustParser::ParametersContext>(0);
}

tree::TerminalNode* PythonRustParser::FuncdefContext::ARROW() {
  return getToken(PythonRustParser::ARROW, 0);
}

PythonRustParser::TypeContext* PythonRustParser::FuncdefContext::type() {
  return getRuleContext<PythonRustParser::TypeContext>(0);
}


size_t PythonRustParser::FuncdefContext::getRuleIndex() const {
  return PythonRustParser::RuleFuncdef;
}


std::any PythonRustParser::FuncdefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitFuncdef(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::FuncdefContext* PythonRustParser::funcdef() {
  FuncdefContext *_localctx = _tracker.createInstance<FuncdefContext>(_ctx, getState());
  enterRule(_localctx, 38, PythonRustParser::RuleFuncdef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(254);
    match(PythonRustParser::DEF);
    setState(255);
    match(PythonRustParser::ID);
    setState(256);
    match(PythonRustParser::LPAREN);
    setState(258);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PythonRustParser::ID) {
      setState(257);
      parameters();
    }
    setState(260);
    match(PythonRustParser::RPAREN);
    setState(263);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PythonRustParser::ARROW) {
      setState(261);
      match(PythonRustParser::ARROW);
      setState(262);
      type();
    }
    setState(265);
    match(PythonRustParser::COLON);
    setState(266);
    suite();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassdefContext ------------------------------------------------------------------

PythonRustParser::ClassdefContext::ClassdefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PythonRustParser::ClassdefContext::CLASS() {
  return getToken(PythonRustParser::CLASS, 0);
}

tree::TerminalNode* PythonRustParser::ClassdefContext::ID() {
  return getToken(PythonRustParser::ID, 0);
}

tree::TerminalNode* PythonRustParser::ClassdefContext::COLON() {
  return getToken(PythonRustParser::COLON, 0);
}

PythonRustParser::SuiteContext* PythonRustParser::ClassdefContext::suite() {
  return getRuleContext<PythonRustParser::SuiteContext>(0);
}

tree::TerminalNode* PythonRustParser::ClassdefContext::LPAREN() {
  return getToken(PythonRustParser::LPAREN, 0);
}

tree::TerminalNode* PythonRustParser::ClassdefContext::RPAREN() {
  return getToken(PythonRustParser::RPAREN, 0);
}

PythonRustParser::ArglistContext* PythonRustParser::ClassdefContext::arglist() {
  return getRuleContext<PythonRustParser::ArglistContext>(0);
}


size_t PythonRustParser::ClassdefContext::getRuleIndex() const {
  return PythonRustParser::RuleClassdef;
}


std::any PythonRustParser::ClassdefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitClassdef(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::ClassdefContext* PythonRustParser::classdef() {
  ClassdefContext *_localctx = _tracker.createInstance<ClassdefContext>(_ctx, getState());
  enterRule(_localctx, 40, PythonRustParser::RuleClassdef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(268);
    match(PythonRustParser::CLASS);
    setState(269);
    match(PythonRustParser::ID);
    setState(275);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PythonRustParser::LPAREN) {
      setState(270);
      match(PythonRustParser::LPAREN);
      setState(272);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 16934679865196544) != 0)) {
        setState(271);
        arglist();
      }
      setState(274);
      match(PythonRustParser::RPAREN);
    }
    setState(277);
    match(PythonRustParser::COLON);
    setState(278);
    suite();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SuiteContext ------------------------------------------------------------------

PythonRustParser::SuiteContext::SuiteContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PythonRustParser::Simple_stmtContext* PythonRustParser::SuiteContext::simple_stmt() {
  return getRuleContext<PythonRustParser::Simple_stmtContext>(0);
}

tree::TerminalNode* PythonRustParser::SuiteContext::NEWLINE() {
  return getToken(PythonRustParser::NEWLINE, 0);
}

tree::TerminalNode* PythonRustParser::SuiteContext::INDENT() {
  return getToken(PythonRustParser::INDENT, 0);
}

tree::TerminalNode* PythonRustParser::SuiteContext::DEDENT() {
  return getToken(PythonRustParser::DEDENT, 0);
}

std::vector<PythonRustParser::StmtContext *> PythonRustParser::SuiteContext::stmt() {
  return getRuleContexts<PythonRustParser::StmtContext>();
}

PythonRustParser::StmtContext* PythonRustParser::SuiteContext::stmt(size_t i) {
  return getRuleContext<PythonRustParser::StmtContext>(i);
}


size_t PythonRustParser::SuiteContext::getRuleIndex() const {
  return PythonRustParser::RuleSuite;
}


std::any PythonRustParser::SuiteContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitSuite(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::SuiteContext* PythonRustParser::suite() {
  SuiteContext *_localctx = _tracker.createInstance<SuiteContext>(_ctx, getState());
  enterRule(_localctx, 42, PythonRustParser::RuleSuite);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(290);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PythonRustParser::RETURN:
      case PythonRustParser::BREAK:
      case PythonRustParser::CONTINUE:
      case PythonRustParser::PASS:
      case PythonRustParser::RAISE:
      case PythonRustParser::IMPORT:
      case PythonRustParser::FROM:
      case PythonRustParser::TRUE:
      case PythonRustParser::FALSE:
      case PythonRustParser::NONE:
      case PythonRustParser::NOT:
      case PythonRustParser::PLUS:
      case PythonRustParser::MINUS:
      case PythonRustParser::LPAREN:
      case PythonRustParser::LBRACK:
      case PythonRustParser::LBRACE:
      case PythonRustParser::FLOAT:
      case PythonRustParser::INT:
      case PythonRustParser::STRING:
      case PythonRustParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(280);
        simple_stmt();
        break;
      }

      case PythonRustParser::NEWLINE: {
        enterOuterAlt(_localctx, 2);
        setState(281);
        match(PythonRustParser::NEWLINE);
        setState(282);
        match(PythonRustParser::INDENT);
        setState(284); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(283);
          stmt();
          setState(286); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 16934679867194168) != 0));
        setState(288);
        match(PythonRustParser::DEDENT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

PythonRustParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PythonRustParser::ParamContext *> PythonRustParser::ParametersContext::param() {
  return getRuleContexts<PythonRustParser::ParamContext>();
}

PythonRustParser::ParamContext* PythonRustParser::ParametersContext::param(size_t i) {
  return getRuleContext<PythonRustParser::ParamContext>(i);
}

std::vector<tree::TerminalNode *> PythonRustParser::ParametersContext::COMMA() {
  return getTokens(PythonRustParser::COMMA);
}

tree::TerminalNode* PythonRustParser::ParametersContext::COMMA(size_t i) {
  return getToken(PythonRustParser::COMMA, i);
}


size_t PythonRustParser::ParametersContext::getRuleIndex() const {
  return PythonRustParser::RuleParameters;
}


std::any PythonRustParser::ParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitParameters(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::ParametersContext* PythonRustParser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 44, PythonRustParser::RuleParameters);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(292);
    param();
    setState(297);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(293);
        match(PythonRustParser::COMMA);
        setState(294);
        param(); 
      }
      setState(299);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    }
    setState(301);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PythonRustParser::COMMA) {
      setState(300);
      match(PythonRustParser::COMMA);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamContext ------------------------------------------------------------------

PythonRustParser::ParamContext::ParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PythonRustParser::ParamContext::ID() {
  return getToken(PythonRustParser::ID, 0);
}

tree::TerminalNode* PythonRustParser::ParamContext::COLON() {
  return getToken(PythonRustParser::COLON, 0);
}

PythonRustParser::TypeContext* PythonRustParser::ParamContext::type() {
  return getRuleContext<PythonRustParser::TypeContext>(0);
}

tree::TerminalNode* PythonRustParser::ParamContext::ASSIGN() {
  return getToken(PythonRustParser::ASSIGN, 0);
}

PythonRustParser::ExprContext* PythonRustParser::ParamContext::expr() {
  return getRuleContext<PythonRustParser::ExprContext>(0);
}


size_t PythonRustParser::ParamContext::getRuleIndex() const {
  return PythonRustParser::RuleParam;
}


std::any PythonRustParser::ParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitParam(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::ParamContext* PythonRustParser::param() {
  ParamContext *_localctx = _tracker.createInstance<ParamContext>(_ctx, getState());
  enterRule(_localctx, 46, PythonRustParser::RuleParam);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(303);
    match(PythonRustParser::ID);
    setState(306);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PythonRustParser::COLON) {
      setState(304);
      match(PythonRustParser::COLON);
      setState(305);
      type();
    }
    setState(310);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PythonRustParser::ASSIGN) {
      setState(308);
      match(PythonRustParser::ASSIGN);
      setState(309);
      expr(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArglistContext ------------------------------------------------------------------

PythonRustParser::ArglistContext::ArglistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PythonRustParser::ArgumentContext *> PythonRustParser::ArglistContext::argument() {
  return getRuleContexts<PythonRustParser::ArgumentContext>();
}

PythonRustParser::ArgumentContext* PythonRustParser::ArglistContext::argument(size_t i) {
  return getRuleContext<PythonRustParser::ArgumentContext>(i);
}

std::vector<tree::TerminalNode *> PythonRustParser::ArglistContext::COMMA() {
  return getTokens(PythonRustParser::COMMA);
}

tree::TerminalNode* PythonRustParser::ArglistContext::COMMA(size_t i) {
  return getToken(PythonRustParser::COMMA, i);
}


size_t PythonRustParser::ArglistContext::getRuleIndex() const {
  return PythonRustParser::RuleArglist;
}


std::any PythonRustParser::ArglistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitArglist(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::ArglistContext* PythonRustParser::arglist() {
  ArglistContext *_localctx = _tracker.createInstance<ArglistContext>(_ctx, getState());
  enterRule(_localctx, 48, PythonRustParser::RuleArglist);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(312);
    argument();
    setState(317);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(313);
        match(PythonRustParser::COMMA);
        setState(314);
        argument(); 
      }
      setState(319);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    }
    setState(321);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PythonRustParser::COMMA) {
      setState(320);
      match(PythonRustParser::COMMA);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentContext ------------------------------------------------------------------

PythonRustParser::ArgumentContext::ArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PythonRustParser::ArgumentContext::getRuleIndex() const {
  return PythonRustParser::RuleArgument;
}

void PythonRustParser::ArgumentContext::copyFrom(ArgumentContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- PosArgContext ------------------------------------------------------------------

PythonRustParser::ExprContext* PythonRustParser::PosArgContext::expr() {
  return getRuleContext<PythonRustParser::ExprContext>(0);
}

PythonRustParser::PosArgContext::PosArgContext(ArgumentContext *ctx) { copyFrom(ctx); }


std::any PythonRustParser::PosArgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitPosArg(this);
  else
    return visitor->visitChildren(this);
}
//----------------- KwArgContext ------------------------------------------------------------------

tree::TerminalNode* PythonRustParser::KwArgContext::ID() {
  return getToken(PythonRustParser::ID, 0);
}

tree::TerminalNode* PythonRustParser::KwArgContext::ASSIGN() {
  return getToken(PythonRustParser::ASSIGN, 0);
}

PythonRustParser::ExprContext* PythonRustParser::KwArgContext::expr() {
  return getRuleContext<PythonRustParser::ExprContext>(0);
}

PythonRustParser::KwArgContext::KwArgContext(ArgumentContext *ctx) { copyFrom(ctx); }


std::any PythonRustParser::KwArgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitKwArg(this);
  else
    return visitor->visitChildren(this);
}
PythonRustParser::ArgumentContext* PythonRustParser::argument() {
  ArgumentContext *_localctx = _tracker.createInstance<ArgumentContext>(_ctx, getState());
  enterRule(_localctx, 50, PythonRustParser::RuleArgument);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(327);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<PythonRustParser::KwArgContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(323);
      match(PythonRustParser::ID);
      setState(324);
      match(PythonRustParser::ASSIGN);
      setState(325);
      expr(0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<PythonRustParser::PosArgContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(326);
      expr(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Target_listContext ------------------------------------------------------------------

PythonRustParser::Target_listContext::Target_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PythonRustParser::TargetContext *> PythonRustParser::Target_listContext::target() {
  return getRuleContexts<PythonRustParser::TargetContext>();
}

PythonRustParser::TargetContext* PythonRustParser::Target_listContext::target(size_t i) {
  return getRuleContext<PythonRustParser::TargetContext>(i);
}

std::vector<tree::TerminalNode *> PythonRustParser::Target_listContext::COMMA() {
  return getTokens(PythonRustParser::COMMA);
}

tree::TerminalNode* PythonRustParser::Target_listContext::COMMA(size_t i) {
  return getToken(PythonRustParser::COMMA, i);
}


size_t PythonRustParser::Target_listContext::getRuleIndex() const {
  return PythonRustParser::RuleTarget_list;
}


std::any PythonRustParser::Target_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitTarget_list(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::Target_listContext* PythonRustParser::target_list() {
  Target_listContext *_localctx = _tracker.createInstance<Target_listContext>(_ctx, getState());
  enterRule(_localctx, 52, PythonRustParser::RuleTarget_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(329);
    target();
    setState(334);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(330);
        match(PythonRustParser::COMMA);
        setState(331);
        target(); 
      }
      setState(336);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
    }
    setState(338);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PythonRustParser::COMMA) {
      setState(337);
      match(PythonRustParser::COMMA);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TargetContext ------------------------------------------------------------------

PythonRustParser::TargetContext::TargetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PythonRustParser::TargetContext::ID() {
  return getToken(PythonRustParser::ID, 0);
}

tree::TerminalNode* PythonRustParser::TargetContext::LPAREN() {
  return getToken(PythonRustParser::LPAREN, 0);
}

PythonRustParser::Target_listContext* PythonRustParser::TargetContext::target_list() {
  return getRuleContext<PythonRustParser::Target_listContext>(0);
}

tree::TerminalNode* PythonRustParser::TargetContext::RPAREN() {
  return getToken(PythonRustParser::RPAREN, 0);
}

tree::TerminalNode* PythonRustParser::TargetContext::LBRACK() {
  return getToken(PythonRustParser::LBRACK, 0);
}

tree::TerminalNode* PythonRustParser::TargetContext::RBRACK() {
  return getToken(PythonRustParser::RBRACK, 0);
}


size_t PythonRustParser::TargetContext::getRuleIndex() const {
  return PythonRustParser::RuleTarget;
}


std::any PythonRustParser::TargetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitTarget(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::TargetContext* PythonRustParser::target() {
  TargetContext *_localctx = _tracker.createInstance<TargetContext>(_ctx, getState());
  enterRule(_localctx, 54, PythonRustParser::RuleTarget);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(349);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PythonRustParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(340);
        match(PythonRustParser::ID);
        break;
      }

      case PythonRustParser::LPAREN: {
        enterOuterAlt(_localctx, 2);
        setState(341);
        match(PythonRustParser::LPAREN);
        setState(342);
        target_list();
        setState(343);
        match(PythonRustParser::RPAREN);
        break;
      }

      case PythonRustParser::LBRACK: {
        enterOuterAlt(_localctx, 3);
        setState(345);
        match(PythonRustParser::LBRACK);
        setState(346);
        target_list();
        setState(347);
        match(PythonRustParser::RBRACK);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TestlistContext ------------------------------------------------------------------

PythonRustParser::TestlistContext::TestlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PythonRustParser::ExprContext *> PythonRustParser::TestlistContext::expr() {
  return getRuleContexts<PythonRustParser::ExprContext>();
}

PythonRustParser::ExprContext* PythonRustParser::TestlistContext::expr(size_t i) {
  return getRuleContext<PythonRustParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> PythonRustParser::TestlistContext::COMMA() {
  return getTokens(PythonRustParser::COMMA);
}

tree::TerminalNode* PythonRustParser::TestlistContext::COMMA(size_t i) {
  return getToken(PythonRustParser::COMMA, i);
}


size_t PythonRustParser::TestlistContext::getRuleIndex() const {
  return PythonRustParser::RuleTestlist;
}


std::any PythonRustParser::TestlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitTestlist(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::TestlistContext* PythonRustParser::testlist() {
  TestlistContext *_localctx = _tracker.createInstance<TestlistContext>(_ctx, getState());
  enterRule(_localctx, 56, PythonRustParser::RuleTestlist);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(351);
    expr(0);
    setState(356);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(352);
        match(PythonRustParser::COMMA);
        setState(353);
        expr(0); 
      }
      setState(358);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx);
    }
    setState(360);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PythonRustParser::COMMA) {
      setState(359);
      match(PythonRustParser::COMMA);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

PythonRustParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PythonRustParser::TypeContext::ID() {
  return getToken(PythonRustParser::ID, 0);
}

tree::TerminalNode* PythonRustParser::TypeContext::LBRACK() {
  return getToken(PythonRustParser::LBRACK, 0);
}

std::vector<PythonRustParser::TypeContext *> PythonRustParser::TypeContext::type() {
  return getRuleContexts<PythonRustParser::TypeContext>();
}

PythonRustParser::TypeContext* PythonRustParser::TypeContext::type(size_t i) {
  return getRuleContext<PythonRustParser::TypeContext>(i);
}

tree::TerminalNode* PythonRustParser::TypeContext::RBRACK() {
  return getToken(PythonRustParser::RBRACK, 0);
}

std::vector<tree::TerminalNode *> PythonRustParser::TypeContext::COMMA() {
  return getTokens(PythonRustParser::COMMA);
}

tree::TerminalNode* PythonRustParser::TypeContext::COMMA(size_t i) {
  return getToken(PythonRustParser::COMMA, i);
}

tree::TerminalNode* PythonRustParser::TypeContext::NONE() {
  return getToken(PythonRustParser::NONE, 0);
}


size_t PythonRustParser::TypeContext::getRuleIndex() const {
  return PythonRustParser::RuleType;
}


std::any PythonRustParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::TypeContext* PythonRustParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 58, PythonRustParser::RuleType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(377);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PythonRustParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(362);
        match(PythonRustParser::ID);
        setState(374);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PythonRustParser::LBRACK) {
          setState(363);
          match(PythonRustParser::LBRACK);
          setState(364);
          type();
          setState(369);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == PythonRustParser::COMMA) {
            setState(365);
            match(PythonRustParser::COMMA);
            setState(366);
            type();
            setState(371);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(372);
          match(PythonRustParser::RBRACK);
        }
        break;
      }

      case PythonRustParser::NONE: {
        enterOuterAlt(_localctx, 2);
        setState(376);
        match(PythonRustParser::NONE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

PythonRustParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PythonRustParser::ExprContext::getRuleIndex() const {
  return PythonRustParser::RuleExpr;
}

void PythonRustParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AndExprContext ------------------------------------------------------------------

std::vector<PythonRustParser::ExprContext *> PythonRustParser::AndExprContext::expr() {
  return getRuleContexts<PythonRustParser::ExprContext>();
}

PythonRustParser::ExprContext* PythonRustParser::AndExprContext::expr(size_t i) {
  return getRuleContext<PythonRustParser::ExprContext>(i);
}

tree::TerminalNode* PythonRustParser::AndExprContext::AND() {
  return getToken(PythonRustParser::AND, 0);
}

PythonRustParser::AndExprContext::AndExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any PythonRustParser::AndExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitAndExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MulDivExprContext ------------------------------------------------------------------

std::vector<PythonRustParser::ExprContext *> PythonRustParser::MulDivExprContext::expr() {
  return getRuleContexts<PythonRustParser::ExprContext>();
}

PythonRustParser::ExprContext* PythonRustParser::MulDivExprContext::expr(size_t i) {
  return getRuleContext<PythonRustParser::ExprContext>(i);
}

tree::TerminalNode* PythonRustParser::MulDivExprContext::STAR() {
  return getToken(PythonRustParser::STAR, 0);
}

tree::TerminalNode* PythonRustParser::MulDivExprContext::DIV() {
  return getToken(PythonRustParser::DIV, 0);
}

tree::TerminalNode* PythonRustParser::MulDivExprContext::MOD() {
  return getToken(PythonRustParser::MOD, 0);
}

PythonRustParser::MulDivExprContext::MulDivExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any PythonRustParser::MulDivExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitMulDivExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MemberExprContext ------------------------------------------------------------------

PythonRustParser::ExprContext* PythonRustParser::MemberExprContext::expr() {
  return getRuleContext<PythonRustParser::ExprContext>(0);
}

tree::TerminalNode* PythonRustParser::MemberExprContext::DOT() {
  return getToken(PythonRustParser::DOT, 0);
}

tree::TerminalNode* PythonRustParser::MemberExprContext::ID() {
  return getToken(PythonRustParser::ID, 0);
}

PythonRustParser::MemberExprContext::MemberExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any PythonRustParser::MemberExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitMemberExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CompExprContext ------------------------------------------------------------------

std::vector<PythonRustParser::ExprContext *> PythonRustParser::CompExprContext::expr() {
  return getRuleContexts<PythonRustParser::ExprContext>();
}

PythonRustParser::ExprContext* PythonRustParser::CompExprContext::expr(size_t i) {
  return getRuleContext<PythonRustParser::ExprContext>(i);
}

tree::TerminalNode* PythonRustParser::CompExprContext::LT() {
  return getToken(PythonRustParser::LT, 0);
}

tree::TerminalNode* PythonRustParser::CompExprContext::GT() {
  return getToken(PythonRustParser::GT, 0);
}

tree::TerminalNode* PythonRustParser::CompExprContext::LE() {
  return getToken(PythonRustParser::LE, 0);
}

tree::TerminalNode* PythonRustParser::CompExprContext::GE() {
  return getToken(PythonRustParser::GE, 0);
}

tree::TerminalNode* PythonRustParser::CompExprContext::EQ() {
  return getToken(PythonRustParser::EQ, 0);
}

tree::TerminalNode* PythonRustParser::CompExprContext::NEQ() {
  return getToken(PythonRustParser::NEQ, 0);
}

PythonRustParser::CompExprContext::CompExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any PythonRustParser::CompExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitCompExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CallExprContext ------------------------------------------------------------------

PythonRustParser::ExprContext* PythonRustParser::CallExprContext::expr() {
  return getRuleContext<PythonRustParser::ExprContext>(0);
}

tree::TerminalNode* PythonRustParser::CallExprContext::LPAREN() {
  return getToken(PythonRustParser::LPAREN, 0);
}

tree::TerminalNode* PythonRustParser::CallExprContext::RPAREN() {
  return getToken(PythonRustParser::RPAREN, 0);
}

PythonRustParser::ArglistContext* PythonRustParser::CallExprContext::arglist() {
  return getRuleContext<PythonRustParser::ArglistContext>(0);
}

PythonRustParser::CallExprContext::CallExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any PythonRustParser::CallExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitCallExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotExprContext ------------------------------------------------------------------

tree::TerminalNode* PythonRustParser::NotExprContext::NOT() {
  return getToken(PythonRustParser::NOT, 0);
}

PythonRustParser::ExprContext* PythonRustParser::NotExprContext::expr() {
  return getRuleContext<PythonRustParser::ExprContext>(0);
}

PythonRustParser::NotExprContext::NotExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any PythonRustParser::NotExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitNotExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AtomExprContext ------------------------------------------------------------------

PythonRustParser::AtomContext* PythonRustParser::AtomExprContext::atom() {
  return getRuleContext<PythonRustParser::AtomContext>(0);
}

PythonRustParser::AtomExprContext::AtomExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any PythonRustParser::AtomExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitAtomExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryExprContext ------------------------------------------------------------------

PythonRustParser::ExprContext* PythonRustParser::UnaryExprContext::expr() {
  return getRuleContext<PythonRustParser::ExprContext>(0);
}

tree::TerminalNode* PythonRustParser::UnaryExprContext::PLUS() {
  return getToken(PythonRustParser::PLUS, 0);
}

tree::TerminalNode* PythonRustParser::UnaryExprContext::MINUS() {
  return getToken(PythonRustParser::MINUS, 0);
}

PythonRustParser::UnaryExprContext::UnaryExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any PythonRustParser::UnaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitUnaryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddSubExprContext ------------------------------------------------------------------

std::vector<PythonRustParser::ExprContext *> PythonRustParser::AddSubExprContext::expr() {
  return getRuleContexts<PythonRustParser::ExprContext>();
}

PythonRustParser::ExprContext* PythonRustParser::AddSubExprContext::expr(size_t i) {
  return getRuleContext<PythonRustParser::ExprContext>(i);
}

tree::TerminalNode* PythonRustParser::AddSubExprContext::PLUS() {
  return getToken(PythonRustParser::PLUS, 0);
}

tree::TerminalNode* PythonRustParser::AddSubExprContext::MINUS() {
  return getToken(PythonRustParser::MINUS, 0);
}

PythonRustParser::AddSubExprContext::AddSubExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any PythonRustParser::AddSubExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitAddSubExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OrExprContext ------------------------------------------------------------------

std::vector<PythonRustParser::ExprContext *> PythonRustParser::OrExprContext::expr() {
  return getRuleContexts<PythonRustParser::ExprContext>();
}

PythonRustParser::ExprContext* PythonRustParser::OrExprContext::expr(size_t i) {
  return getRuleContext<PythonRustParser::ExprContext>(i);
}

tree::TerminalNode* PythonRustParser::OrExprContext::OR() {
  return getToken(PythonRustParser::OR, 0);
}

PythonRustParser::OrExprContext::OrExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any PythonRustParser::OrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitOrExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IndexExprContext ------------------------------------------------------------------

PythonRustParser::ExprContext* PythonRustParser::IndexExprContext::expr() {
  return getRuleContext<PythonRustParser::ExprContext>(0);
}

tree::TerminalNode* PythonRustParser::IndexExprContext::LBRACK() {
  return getToken(PythonRustParser::LBRACK, 0);
}

PythonRustParser::SubscriptContext* PythonRustParser::IndexExprContext::subscript() {
  return getRuleContext<PythonRustParser::SubscriptContext>(0);
}

tree::TerminalNode* PythonRustParser::IndexExprContext::RBRACK() {
  return getToken(PythonRustParser::RBRACK, 0);
}

PythonRustParser::IndexExprContext::IndexExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any PythonRustParser::IndexExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitIndexExpr(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::ExprContext* PythonRustParser::expr() {
   return expr(0);
}

PythonRustParser::ExprContext* PythonRustParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PythonRustParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  PythonRustParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 60;
  enterRecursionRule(_localctx, 60, PythonRustParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(385);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PythonRustParser::PLUS:
      case PythonRustParser::MINUS: {
        _localctx = _tracker.createInstance<UnaryExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(380);
        _la = _input->LA(1);
        if (!(_la == PythonRustParser::PLUS

        || _la == PythonRustParser::MINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(381);
        expr(8);
        break;
      }

      case PythonRustParser::NOT: {
        _localctx = _tracker.createInstance<NotExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(382);
        match(PythonRustParser::NOT);
        setState(383);
        expr(4);
        break;
      }

      case PythonRustParser::TRUE:
      case PythonRustParser::FALSE:
      case PythonRustParser::NONE:
      case PythonRustParser::LPAREN:
      case PythonRustParser::LBRACK:
      case PythonRustParser::LBRACE:
      case PythonRustParser::FLOAT:
      case PythonRustParser::INT:
      case PythonRustParser::STRING:
      case PythonRustParser::ID: {
        _localctx = _tracker.createInstance<AtomExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(384);
        atom();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(418);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(416);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulDivExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(387);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(388);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 15032385536) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(389);
          expr(8);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddSubExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(390);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(391);
          _la = _input->LA(1);
          if (!(_la == PythonRustParser::PLUS

          || _la == PythonRustParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(392);
          expr(7);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<CompExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(393);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(394);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 1906965479424) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(395);
          expr(6);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<AndExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(396);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(397);
          match(PythonRustParser::AND);
          setState(398);
          expr(4);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<OrExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(399);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(400);
          match(PythonRustParser::OR);
          setState(401);
          expr(3);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<CallExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(402);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(403);
          match(PythonRustParser::LPAREN);
          setState(405);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 16934679865196544) != 0)) {
            setState(404);
            arglist();
          }
          setState(407);
          match(PythonRustParser::RPAREN);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<IndexExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(408);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(409);
          match(PythonRustParser::LBRACK);
          setState(410);
          subscript();
          setState(411);
          match(PythonRustParser::RBRACK);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<MemberExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(413);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(414);
          match(PythonRustParser::DOT);
          setState(415);
          match(PythonRustParser::ID);
          break;
        }

        default:
          break;
        } 
      }
      setState(420);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- SubscriptContext ------------------------------------------------------------------

PythonRustParser::SubscriptContext::SubscriptContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PythonRustParser::SliceContext* PythonRustParser::SubscriptContext::slice() {
  return getRuleContext<PythonRustParser::SliceContext>(0);
}

PythonRustParser::ExprContext* PythonRustParser::SubscriptContext::expr() {
  return getRuleContext<PythonRustParser::ExprContext>(0);
}


size_t PythonRustParser::SubscriptContext::getRuleIndex() const {
  return PythonRustParser::RuleSubscript;
}


std::any PythonRustParser::SubscriptContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitSubscript(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::SubscriptContext* PythonRustParser::subscript() {
  SubscriptContext *_localctx = _tracker.createInstance<SubscriptContext>(_ctx, getState());
  enterRule(_localctx, 62, PythonRustParser::RuleSubscript);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(423);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(421);
      slice();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(422);
      expr(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SliceContext ------------------------------------------------------------------

PythonRustParser::SliceContext::SliceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> PythonRustParser::SliceContext::COLON() {
  return getTokens(PythonRustParser::COLON);
}

tree::TerminalNode* PythonRustParser::SliceContext::COLON(size_t i) {
  return getToken(PythonRustParser::COLON, i);
}

std::vector<PythonRustParser::ExprContext *> PythonRustParser::SliceContext::expr() {
  return getRuleContexts<PythonRustParser::ExprContext>();
}

PythonRustParser::ExprContext* PythonRustParser::SliceContext::expr(size_t i) {
  return getRuleContext<PythonRustParser::ExprContext>(i);
}


size_t PythonRustParser::SliceContext::getRuleIndex() const {
  return PythonRustParser::RuleSlice;
}


std::any PythonRustParser::SliceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitSlice(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::SliceContext* PythonRustParser::slice() {
  SliceContext *_localctx = _tracker.createInstance<SliceContext>(_ctx, getState());
  enterRule(_localctx, 64, PythonRustParser::RuleSlice);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(426);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 16934679865196544) != 0)) {
      setState(425);
      expr(0);
    }
    setState(428);
    match(PythonRustParser::COLON);
    setState(430);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 16934679865196544) != 0)) {
      setState(429);
      expr(0);
    }
    setState(436);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PythonRustParser::COLON) {
      setState(432);
      match(PythonRustParser::COLON);
      setState(434);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 16934679865196544) != 0)) {
        setState(433);
        expr(0);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AtomContext ------------------------------------------------------------------

PythonRustParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PythonRustParser::AtomContext::getRuleIndex() const {
  return PythonRustParser::RuleAtom;
}

void PythonRustParser::AtomContext::copyFrom(AtomContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- GroupOrTupleAtomContext ------------------------------------------------------------------

tree::TerminalNode* PythonRustParser::GroupOrTupleAtomContext::LPAREN() {
  return getToken(PythonRustParser::LPAREN, 0);
}

tree::TerminalNode* PythonRustParser::GroupOrTupleAtomContext::RPAREN() {
  return getToken(PythonRustParser::RPAREN, 0);
}

PythonRustParser::TestlistContext* PythonRustParser::GroupOrTupleAtomContext::testlist() {
  return getRuleContext<PythonRustParser::TestlistContext>(0);
}

PythonRustParser::GroupOrTupleAtomContext::GroupOrTupleAtomContext(AtomContext *ctx) { copyFrom(ctx); }


std::any PythonRustParser::GroupOrTupleAtomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitGroupOrTupleAtom(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TrueAtomContext ------------------------------------------------------------------

tree::TerminalNode* PythonRustParser::TrueAtomContext::TRUE() {
  return getToken(PythonRustParser::TRUE, 0);
}

PythonRustParser::TrueAtomContext::TrueAtomContext(AtomContext *ctx) { copyFrom(ctx); }


std::any PythonRustParser::TrueAtomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitTrueAtom(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FalseAtomContext ------------------------------------------------------------------

tree::TerminalNode* PythonRustParser::FalseAtomContext::FALSE() {
  return getToken(PythonRustParser::FALSE, 0);
}

PythonRustParser::FalseAtomContext::FalseAtomContext(AtomContext *ctx) { copyFrom(ctx); }


std::any PythonRustParser::FalseAtomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitFalseAtom(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringAtomContext ------------------------------------------------------------------

tree::TerminalNode* PythonRustParser::StringAtomContext::STRING() {
  return getToken(PythonRustParser::STRING, 0);
}

PythonRustParser::StringAtomContext::StringAtomContext(AtomContext *ctx) { copyFrom(ctx); }


std::any PythonRustParser::StringAtomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitStringAtom(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SetDictAtomContext ------------------------------------------------------------------

PythonRustParser::Set_or_dictContext* PythonRustParser::SetDictAtomContext::set_or_dict() {
  return getRuleContext<PythonRustParser::Set_or_dictContext>(0);
}

PythonRustParser::SetDictAtomContext::SetDictAtomContext(AtomContext *ctx) { copyFrom(ctx); }


std::any PythonRustParser::SetDictAtomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitSetDictAtom(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ListAtomContext ------------------------------------------------------------------

PythonRustParser::List_makerContext* PythonRustParser::ListAtomContext::list_maker() {
  return getRuleContext<PythonRustParser::List_makerContext>(0);
}

PythonRustParser::ListAtomContext::ListAtomContext(AtomContext *ctx) { copyFrom(ctx); }


std::any PythonRustParser::ListAtomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitListAtom(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NoneAtomContext ------------------------------------------------------------------

tree::TerminalNode* PythonRustParser::NoneAtomContext::NONE() {
  return getToken(PythonRustParser::NONE, 0);
}

PythonRustParser::NoneAtomContext::NoneAtomContext(AtomContext *ctx) { copyFrom(ctx); }


std::any PythonRustParser::NoneAtomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitNoneAtom(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FloatAtomContext ------------------------------------------------------------------

tree::TerminalNode* PythonRustParser::FloatAtomContext::FLOAT() {
  return getToken(PythonRustParser::FLOAT, 0);
}

PythonRustParser::FloatAtomContext::FloatAtomContext(AtomContext *ctx) { copyFrom(ctx); }


std::any PythonRustParser::FloatAtomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitFloatAtom(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntAtomContext ------------------------------------------------------------------

tree::TerminalNode* PythonRustParser::IntAtomContext::INT() {
  return getToken(PythonRustParser::INT, 0);
}

PythonRustParser::IntAtomContext::IntAtomContext(AtomContext *ctx) { copyFrom(ctx); }


std::any PythonRustParser::IntAtomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitIntAtom(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdAtomContext ------------------------------------------------------------------

tree::TerminalNode* PythonRustParser::IdAtomContext::ID() {
  return getToken(PythonRustParser::ID, 0);
}

PythonRustParser::IdAtomContext::IdAtomContext(AtomContext *ctx) { copyFrom(ctx); }


std::any PythonRustParser::IdAtomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitIdAtom(this);
  else
    return visitor->visitChildren(this);
}
PythonRustParser::AtomContext* PythonRustParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 66, PythonRustParser::RuleAtom);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(452);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PythonRustParser::INT: {
        _localctx = _tracker.createInstance<PythonRustParser::IntAtomContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(438);
        match(PythonRustParser::INT);
        break;
      }

      case PythonRustParser::FLOAT: {
        _localctx = _tracker.createInstance<PythonRustParser::FloatAtomContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(439);
        match(PythonRustParser::FLOAT);
        break;
      }

      case PythonRustParser::STRING: {
        _localctx = _tracker.createInstance<PythonRustParser::StringAtomContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(440);
        match(PythonRustParser::STRING);
        break;
      }

      case PythonRustParser::TRUE: {
        _localctx = _tracker.createInstance<PythonRustParser::TrueAtomContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(441);
        match(PythonRustParser::TRUE);
        break;
      }

      case PythonRustParser::FALSE: {
        _localctx = _tracker.createInstance<PythonRustParser::FalseAtomContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(442);
        match(PythonRustParser::FALSE);
        break;
      }

      case PythonRustParser::NONE: {
        _localctx = _tracker.createInstance<PythonRustParser::NoneAtomContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(443);
        match(PythonRustParser::NONE);
        break;
      }

      case PythonRustParser::ID: {
        _localctx = _tracker.createInstance<PythonRustParser::IdAtomContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(444);
        match(PythonRustParser::ID);
        break;
      }

      case PythonRustParser::LBRACK: {
        _localctx = _tracker.createInstance<PythonRustParser::ListAtomContext>(_localctx);
        enterOuterAlt(_localctx, 8);
        setState(445);
        list_maker();
        break;
      }

      case PythonRustParser::LBRACE: {
        _localctx = _tracker.createInstance<PythonRustParser::SetDictAtomContext>(_localctx);
        enterOuterAlt(_localctx, 9);
        setState(446);
        set_or_dict();
        break;
      }

      case PythonRustParser::LPAREN: {
        _localctx = _tracker.createInstance<PythonRustParser::GroupOrTupleAtomContext>(_localctx);
        enterOuterAlt(_localctx, 10);
        setState(447);
        match(PythonRustParser::LPAREN);
        setState(449);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 16934679865196544) != 0)) {
          setState(448);
          testlist();
        }
        setState(451);
        match(PythonRustParser::RPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- List_makerContext ------------------------------------------------------------------

PythonRustParser::List_makerContext::List_makerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PythonRustParser::List_makerContext::LBRACK() {
  return getToken(PythonRustParser::LBRACK, 0);
}

tree::TerminalNode* PythonRustParser::List_makerContext::RBRACK() {
  return getToken(PythonRustParser::RBRACK, 0);
}

std::vector<PythonRustParser::ExprContext *> PythonRustParser::List_makerContext::expr() {
  return getRuleContexts<PythonRustParser::ExprContext>();
}

PythonRustParser::ExprContext* PythonRustParser::List_makerContext::expr(size_t i) {
  return getRuleContext<PythonRustParser::ExprContext>(i);
}

PythonRustParser::Comp_clauseContext* PythonRustParser::List_makerContext::comp_clause() {
  return getRuleContext<PythonRustParser::Comp_clauseContext>(0);
}

std::vector<tree::TerminalNode *> PythonRustParser::List_makerContext::COMMA() {
  return getTokens(PythonRustParser::COMMA);
}

tree::TerminalNode* PythonRustParser::List_makerContext::COMMA(size_t i) {
  return getToken(PythonRustParser::COMMA, i);
}


size_t PythonRustParser::List_makerContext::getRuleIndex() const {
  return PythonRustParser::RuleList_maker;
}


std::any PythonRustParser::List_makerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitList_maker(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::List_makerContext* PythonRustParser::list_maker() {
  List_makerContext *_localctx = _tracker.createInstance<List_makerContext>(_ctx, getState());
  enterRule(_localctx, 68, PythonRustParser::RuleList_maker);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(454);
    match(PythonRustParser::LBRACK);
    setState(469);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx)) {
    case 1: {
      setState(455);
      expr(0);
      setState(456);
      comp_clause();
      break;
    }

    case 2: {
      setState(458);
      expr(0);
      setState(463);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(459);
          match(PythonRustParser::COMMA);
          setState(460);
          expr(0); 
        }
        setState(465);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx);
      }
      setState(467);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PythonRustParser::COMMA) {
        setState(466);
        match(PythonRustParser::COMMA);
      }
      break;
    }

    default:
      break;
    }
    setState(471);
    match(PythonRustParser::RBRACK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Set_or_dictContext ------------------------------------------------------------------

PythonRustParser::Set_or_dictContext::Set_or_dictContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PythonRustParser::Set_or_dictContext::LBRACE() {
  return getToken(PythonRustParser::LBRACE, 0);
}

tree::TerminalNode* PythonRustParser::Set_or_dictContext::RBRACE() {
  return getToken(PythonRustParser::RBRACE, 0);
}

std::vector<PythonRustParser::Dict_kvContext *> PythonRustParser::Set_or_dictContext::dict_kv() {
  return getRuleContexts<PythonRustParser::Dict_kvContext>();
}

PythonRustParser::Dict_kvContext* PythonRustParser::Set_or_dictContext::dict_kv(size_t i) {
  return getRuleContext<PythonRustParser::Dict_kvContext>(i);
}

PythonRustParser::Comp_clauseContext* PythonRustParser::Set_or_dictContext::comp_clause() {
  return getRuleContext<PythonRustParser::Comp_clauseContext>(0);
}

std::vector<PythonRustParser::ExprContext *> PythonRustParser::Set_or_dictContext::expr() {
  return getRuleContexts<PythonRustParser::ExprContext>();
}

PythonRustParser::ExprContext* PythonRustParser::Set_or_dictContext::expr(size_t i) {
  return getRuleContext<PythonRustParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> PythonRustParser::Set_or_dictContext::COMMA() {
  return getTokens(PythonRustParser::COMMA);
}

tree::TerminalNode* PythonRustParser::Set_or_dictContext::COMMA(size_t i) {
  return getToken(PythonRustParser::COMMA, i);
}


size_t PythonRustParser::Set_or_dictContext::getRuleIndex() const {
  return PythonRustParser::RuleSet_or_dict;
}


std::any PythonRustParser::Set_or_dictContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitSet_or_dict(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::Set_or_dictContext* PythonRustParser::set_or_dict() {
  Set_or_dictContext *_localctx = _tracker.createInstance<Set_or_dictContext>(_ctx, getState());
  enterRule(_localctx, 70, PythonRustParser::RuleSet_or_dict);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(473);
    match(PythonRustParser::LBRACE);
    setState(502);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx)) {
    case 1: {
      setState(474);
      dict_kv();
      setState(475);
      comp_clause();
      break;
    }

    case 2: {
      setState(477);
      dict_kv();
      setState(482);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(478);
          match(PythonRustParser::COMMA);
          setState(479);
          dict_kv(); 
        }
        setState(484);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx);
      }
      setState(486);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PythonRustParser::COMMA) {
        setState(485);
        match(PythonRustParser::COMMA);
      }
      break;
    }

    case 3: {
      setState(488);
      expr(0);
      setState(489);
      comp_clause();
      break;
    }

    case 4: {
      setState(491);
      expr(0);
      setState(496);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(492);
          match(PythonRustParser::COMMA);
          setState(493);
          expr(0); 
        }
        setState(498);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
      }
      setState(500);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PythonRustParser::COMMA) {
        setState(499);
        match(PythonRustParser::COMMA);
      }
      break;
    }

    default:
      break;
    }
    setState(504);
    match(PythonRustParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Dict_kvContext ------------------------------------------------------------------

PythonRustParser::Dict_kvContext::Dict_kvContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PythonRustParser::ExprContext *> PythonRustParser::Dict_kvContext::expr() {
  return getRuleContexts<PythonRustParser::ExprContext>();
}

PythonRustParser::ExprContext* PythonRustParser::Dict_kvContext::expr(size_t i) {
  return getRuleContext<PythonRustParser::ExprContext>(i);
}

tree::TerminalNode* PythonRustParser::Dict_kvContext::COLON() {
  return getToken(PythonRustParser::COLON, 0);
}


size_t PythonRustParser::Dict_kvContext::getRuleIndex() const {
  return PythonRustParser::RuleDict_kv;
}


std::any PythonRustParser::Dict_kvContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitDict_kv(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::Dict_kvContext* PythonRustParser::dict_kv() {
  Dict_kvContext *_localctx = _tracker.createInstance<Dict_kvContext>(_ctx, getState());
  enterRule(_localctx, 72, PythonRustParser::RuleDict_kv);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(506);
    expr(0);
    setState(507);
    match(PythonRustParser::COLON);
    setState(508);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Comp_clauseContext ------------------------------------------------------------------

PythonRustParser::Comp_clauseContext::Comp_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PythonRustParser::Comp_clauseContext::FOR() {
  return getToken(PythonRustParser::FOR, 0);
}

PythonRustParser::Target_listContext* PythonRustParser::Comp_clauseContext::target_list() {
  return getRuleContext<PythonRustParser::Target_listContext>(0);
}

tree::TerminalNode* PythonRustParser::Comp_clauseContext::IN() {
  return getToken(PythonRustParser::IN, 0);
}

std::vector<PythonRustParser::ExprContext *> PythonRustParser::Comp_clauseContext::expr() {
  return getRuleContexts<PythonRustParser::ExprContext>();
}

PythonRustParser::ExprContext* PythonRustParser::Comp_clauseContext::expr(size_t i) {
  return getRuleContext<PythonRustParser::ExprContext>(i);
}

tree::TerminalNode* PythonRustParser::Comp_clauseContext::IF() {
  return getToken(PythonRustParser::IF, 0);
}

PythonRustParser::Comp_clauseContext* PythonRustParser::Comp_clauseContext::comp_clause() {
  return getRuleContext<PythonRustParser::Comp_clauseContext>(0);
}


size_t PythonRustParser::Comp_clauseContext::getRuleIndex() const {
  return PythonRustParser::RuleComp_clause;
}


std::any PythonRustParser::Comp_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PythonRustParserVisitor*>(visitor))
    return parserVisitor->visitComp_clause(this);
  else
    return visitor->visitChildren(this);
}

PythonRustParser::Comp_clauseContext* PythonRustParser::comp_clause() {
  Comp_clauseContext *_localctx = _tracker.createInstance<Comp_clauseContext>(_ctx, getState());
  enterRule(_localctx, 74, PythonRustParser::RuleComp_clause);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(510);
    match(PythonRustParser::FOR);
    setState(511);
    target_list();
    setState(512);
    match(PythonRustParser::IN);
    setState(513);
    expr(0);
    setState(516);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PythonRustParser::IF) {
      setState(514);
      match(PythonRustParser::IF);
      setState(515);
      expr(0);
    }
    setState(519);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PythonRustParser::FOR) {
      setState(518);
      comp_clause();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool PythonRustParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 30: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool PythonRustParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 7);
    case 1: return precpred(_ctx, 6);
    case 2: return precpred(_ctx, 5);
    case 3: return precpred(_ctx, 3);
    case 4: return precpred(_ctx, 2);
    case 5: return precpred(_ctx, 11);
    case 6: return precpred(_ctx, 10);
    case 7: return precpred(_ctx, 9);

  default:
    break;
  }
  return true;
}

void PythonRustParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  pythonrustparserParserInitialize();
#else
  ::antlr4::internal::call_once(pythonrustparserParserOnceFlag, pythonrustparserParserInitialize);
#endif
}
