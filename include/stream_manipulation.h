#ifndef ANSI_CODES_H
#define ANSI_CODES_H

#include <string>

enum class AnsiColorFG {
		BLACK = 30,
		RED = 31,
		GREEN = 32,
		YELLOW = 33,
		BLUE = 34,
		MAGENTA = 35,
		CYAN = 36,
		WHITE = 37,
		BRIGHT_BLACK = 90,
		BRIGHT_RED = 91,
		BRIGHT_GREEN = 92,
		BRIGHT_YELLOW = 93,
		BRIGHT_BLUE = 94,
		BRIGHT_MAGENTA = 95,
		BRIGHT_CYAN = 96,
		BRIGHT_WHITE = 97
};
enum class AnsiColorBG {
		BLACK = 40,
		RED = 41,
		GREEN = 42,
		YELLOW = 43,
		BLUE = 44,
		MAGENTA = 45,
		CYAN = 46,
		WHITE = 47,
		BRIGHT_BLACK = 100,
		BRIGHT_RED = 101,
		BRIGHT_GREEN = 102,
		BRIGHT_YELLOW = 103,
		BRIGHT_BLUE = 104,
		BRIGHT_MAGENTA = 105,
		BRIGHT_CYAN = 106,
		BRIGHT_WHITE = 107
};

// https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797#screen-modes
enum class AnsiScreen {
		MT40x25 = 0,
		CT40x25 = 1,
		MT80x25 = 0,
		CG320x200_4 = 1,
		MG320x200 = 1,
		MG640x200 = 1,
		LWT = 1,
		CG320x200 = 1,
		CG640x200_16 = 1,
		MG640x350_2 = 1,
		CG640x350_16 = 1,
		MG640x480_2 = 1,
		CG640x480_16 = 1,
		CG320x200_256 = 1
};

enum class AnsiReset {
	RESET = 0
};

std::string customAnsiCode(std::string code, int color);
std::string printAnsiCode(AnsiColorFG color);
std::string printAnsiCode(AnsiColorBG color);
std::string customAnsiCode(int code);
std::string resetAnsiCode();

#endif

