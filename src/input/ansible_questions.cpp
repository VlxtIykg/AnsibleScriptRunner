#include "ansible_questions.h"

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "console_output.h"
#include "move_script.h"
#include "stream_manipulation.h"
#include "utility.h"

void notebooks() {
  bool changedHost;
  bool hostAsArgs; // If hostasargs, require -K for sudo password aswell
  std::string hostnames;
  std::string std_input;
  std::stringstream ss;
  std::vector<std::string> host;
  bool intunes;

  copyAnsibleScripts();

  std::cout << customAnsiCode("", 255);
  ConsoleOutput("Did you change the host in /etc/ansible/hosts?");
  changedHost = yn();
  if (changedHost) {
    hostAsArgs = false;
  } else {
    hostAsArgs = true;
    ConsoleOutput("Please enter the ip addresses of the new laptops. E.g. "
                  "192.168.10.250, 192.168.10.251, 192.168.10.121");
    std::cout << "IP Addresses ";
    std::cout << customAnsiCode("", 240);
    std::cout << "(192.168.10.24, 192.168.10.125)";
    std::cout << customAnsiCode("", 255);
    std::cout << ": ";
    std::getline(std::cin, hostnames);

    std::stringstream ss(hostnames);

    while (ss.good()) {
      std::string substr;
      getline(ss, substr, ',');
      host.push_back(removeSpaces(substr));
    }

    for (size_t i = 0; i < host.size(); i++) {
      std::cout << host[i] << "\n";
    }
  }

  ConsoleOutput("Would you like to install microsoft intunes?");
  intunes = yn();

	if (intunes) {
		if (hostAsArgs) {
      std::string command =
          "ansible-playbook -i " + removeSpaces(hostnames) +
          ", /etc/ansible/playbooks/playbooks/install_tunes.yml";
      system(command.c_str());
		} else {
      system("ansible-playbook /etc/ansible/playbooks/install_tunes.yml");
                }
	}
}