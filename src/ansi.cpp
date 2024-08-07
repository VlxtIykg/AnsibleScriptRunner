#include "stream_manipulation.h"
#include <string>

std::string printAnsiCode(AnsiColorFG color) {
    return "\x1b[" + std::to_string(static_cast<int>(color)) + "m";
}

// std::string printAnsiCode(AnsiColorBG color) {
//     return "\x1b[" + std::to_string(static_cast<int>(color)) + "m";
// }


std::string resetAnsiCode() {
		// enum AnsiReset { RESET = 0 };
		// return "\x1b[" + std::to_string(RESET) + "m";
		return "No reset";
}