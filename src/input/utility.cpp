#include "utility.h"

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

std::string str_tolower(std::string s) {
  std::transform(s.begin(), s.end(), s.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  return s;
}

std::string removeSpaces(std::string str) {
  str.erase(remove(str.begin(), str.end(), ' '), str.end());
  return str;
}

std::string pathToAnsible() {
  std::filesystem::path p = "Test";
  std::string current_pwd = std::filesystem::current_path();
  stringstream ss(current_pwd);
  std::vector<std::string> dir;
  std::vector<std::string> temp_dir;
  std::string temp_dir_stringify;
	char delimiter = '/';
  std::string token;
  size_t pos = 0;

  while (ss.good()) {
    std::string substr;
    getline(ss, substr, delimiter);
    dir.push_back(substr);
  }

  for (; pos < dir.size(); pos++) {
    // std::cout << dir[pos] << "\n";
    auto temp_pos = temp_dir.begin() + pos;
    temp_dir.insert(temp_pos, dir[pos]);
    if (dir[pos] == "AnsibleScriptRunner") {
      // std::string temp_dir_stringify(temp_dir.begin(), temp_dir.end());

      for (const std::string& s : temp_dir) temp_dir_stringify.append("/" + s);
      return temp_dir_stringify;
    }
  }

  return "";
  return "";
}