#include "stream_manipulation.h"
#include <string>

std::string customAnsiCode(std::string code, int color) {
  return "\x1b[38;5;" + std::to_string(color) + "m";
}

std::string printAnsiCode(AnsiColorFG color) {
  return "\x1b[" + std::to_string(static_cast<int>(color)) + "m";
}

std::string printAnsiCode(AnsiColorBG color) {
  return "\x1b[" + std::to_string(static_cast<int>(color)) + "m";
}

std::string resetAnsiCode() { return "\x1b[0m"; }