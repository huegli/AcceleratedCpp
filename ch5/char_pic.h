#ifndef GUARD_char_pic
#define GUARD_char_pic

#include <iostream>
#include <string>
#include <vector>

std::string::size_type width(const std::vector<std::string>&);
std::vector<std::string> frame(const std::vector<std::string>&);
std::vector<std::string> vcat(const std::vector<std::string>&,
        const std::vector<std::string>&);
std::vector<std::string> hcat(const std::vector<std::string>&,
        const std::vector<std::string>&);
#endif

