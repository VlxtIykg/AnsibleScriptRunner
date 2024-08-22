#include "ansible_questions.h"
#include "console_output.h"
#include "stream_manipulation.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int main() {
  system("clear");
  startMessage(); // We start here	

  // This function will settle all in the in between meaning there will not be 4
  // fn(str1) fn(str2) fn(str3) fn(str4) but fn() -> fn1(str1), fn2(str2),
  // fn3(str3), fn4(str4)
	notebooks();

  endMessage(); // We end here
  return 0;
}
