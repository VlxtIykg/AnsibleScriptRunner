#include "console_output.h"
#include "stream_manipulation.h"
#include <format>
#include <iostream>
#include <string>
#include <vector>

AnsiColorFG greenText = AnsiColorFG::BRIGHT_GREEN;
AnsiColorBG blackBG = AnsiColorBG::BLACK;
AnsiColorFG whiteText = AnsiColorFG::WHITE;

std::vector<std::string> wrapper(const std::string &message, size_t width) {
  std::vector<std::string> lines;
  std::string line;

  for (char ch : message) {
    if (line.length() + 1 < width) {
      line += ch;
    } else {
      lines.push_back(line);
      line = ch;
    }
  }
  if (!line.empty()) {
    lines.push_back(line);
  }

  return lines;
}

void dynamicBox(std::string message) {
  size_t bw = 50;
  std::setlocale(LC_ALL, "en_US.UTF-8");

  std::vector<std::string> lines = wrapper(message, bw - 4);

  std::cout << std::format("┌{:─^50}┐", "─") << '\n';

  for (const std::string &line : wrapper(message, bw - 4)) {
    size_t lineLength = line.length();
    size_t totalPadding = bw - lineLength; // Total padding inside the box
    size_t rightPadding = totalPadding / 2;
    size_t leftPadding = totalPadding - rightPadding;

    std::cout << "│" << std::string(leftPadding, ' ') << line;
    std::cout << std::string(rightPadding, ' ') << "│" << std::endl;
  }

  std::cout << std::format("└{:─^50}┘", "") << '\n';
};

void startMessage() {
  std::cout << printAnsiCode(greenText);
  dynamicBox("Welcome to Ansible Runner");
  std::cout << resetAnsiCode();
};

void endMessage() {
  std::cout << printAnsiCode(greenText);
  dynamicBox("You have reached the end of Ansible Runner");
  std::cout << resetAnsiCode();
};

bool yn() {
  std::string val;
  std::cout << "(Y)";
  std::cout << customAnsiCode("", 240);
  std::cout << "es";
  std::cout << customAnsiCode("", 255);
  std::cout << " or (N)";
  std::cout << customAnsiCode("", 240);
  std::cout << "o: ";
  std::cout << customAnsiCode("", 255);
  std::getline(std::cin, val);

  if (val == "y" || val == "ye" || val == "yes") {
    return true;
  } else if (val == "n" || val == "no") {
    return false;
  } else {
    ConsoleOutput("You have entered an invalid option");
    exit(0);
  }
}

void ConsoleOutput(std::string message) { dynamicBox(message); };