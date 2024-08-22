#ifndef movers
#define movers

#include <filesystem>

#include "string"

void copyAnsibleScripts();
std::string get_stem(const std::filesystem::path& p);

#endif