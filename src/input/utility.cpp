#include "utility.h"
#include <algorithm>
#include <cctype>
#include <string>

std::string str_tolower(std::string s) {
  std::transform(s.begin(), s.end(), s.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  return s;
}

std::string removeSpaces(std::string str) {
  str.erase(remove(str.begin(), str.end(), ' '), str.end());
  return str;
}