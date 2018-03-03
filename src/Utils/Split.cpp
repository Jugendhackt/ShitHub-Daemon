//
// Created by anghenfil on 25.02.18.
//

#include <cstring>
#include <iostream>
#include "Split.hpp"

std::vector<std::string> Utils::Split::split(std::string &input) {
    char *token = std::strtok(const_cast<char *>(input.c_str()), " ");
    std::vector<std::string> splitted;

    while (token != nullptr) {
        splitted.emplace_back(token);
        token = std::strtok(nullptr, " ");
    }
    return splitted;
}
