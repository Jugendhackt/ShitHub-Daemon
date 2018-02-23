//
// Created by anghenfil on 13.02.18.
//

#include "ConfigStore.hpp"
#include "../Utils/Filepaths.hpp"

Config::ConfigStore::ConfigStore(const std::string& filepath, const std::string& templatepath) {
    if(Utils::Filepaths::checkPath(filepath)) {
        this->filepath = filepath;
    }
    if(Utils::Filepaths::checkPath(templatepath)) {
        this->templatepath = templatepath;
    }
}

bool Config::ConfigStore::loadValues() {
    return false;
}
