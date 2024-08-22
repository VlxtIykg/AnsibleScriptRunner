#include "move_script.h"

#include <filesystem>
#include <iostream>

#include "stream_manipulation.h"
#include "utility.h"

std::string get_stem(const std::filesystem::path& p) {
  return p.string().erase(0, 1);
}

void copyAnsibleScripts() {
  std::string sourceDir = pathToAnsible() + "/src/ansible";
  std::string destinationDir = "/etc/ansible/playbooks";

  // Fallback incase no playbooks folder
  if (!std::filesystem::exists(destinationDir)) {
    std::filesystem::create_directory(destinationDir);
  }

  std::cout << "Copying Ansible Scripts\n";
  for (const auto& entry : std::filesystem::directory_iterator(sourceDir)) {
    std::cout << customAnsiCode("", 82);
    std::cout << "From: " << get_stem(entry.path()) << customAnsiCode("", 77)
              << "\n";

    std::filesystem::copy(
        get_stem(entry.path()),
        "/etc/ansible/playbooks/" + entry.path().filename().string(),
        std::filesystem::copy_options::update_existing | std::filesystem::copy_options::overwrite_existing);
    std::cout << "To:" 
              << "/etc/ansible/playbooks/" + entry.path().filename().string()
              << "\n";
    std::cout << customAnsiCode("", 255);
  }
}