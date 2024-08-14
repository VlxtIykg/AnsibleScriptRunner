#include <iostream>
#include "stream_manipulation.h"

AnsiColorFG green = AnsiColorFG::BRIGHT_GREEN;
AnsiColorFG white = AnsiColorFG::WHITE;
void startMessage() {
	std::cout << printAnsiCode(green);
	std::cout << " ┌───────────────────────────────┐ \n";
	std::cout << " │   Welcome to Ansible Runner   │ \n";
	std::cout << " └───────────────────────────────┘ \n";
	std::cout << printAnsiCode(white);
	// std::cout << resetAnsiCode(); Not reseting to keep the background, subbing it to white
};

void endMessage() {
	std::cout << printAnsiCode(green);
	std::cout << " ┌────────────────────────────────────────────────┐ \n";
	std::cout << " │   You have reached the end of Ansible Runner   │ \n";
	std::cout << " └────────────────────────────────────────────────┘ \n";
	std::cout << printAnsiCode(white);
};