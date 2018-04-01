//
// Created by anghenfil on 11.01.18.
//

#include "ConfigManager.hpp"

Config::ConfigManager::ConfigManager() : configstores(){}

void Config::ConfigManager::addConfigStore(Config::ConfigStore cs) {
    configstores.insert(std::pair<std::string, Config::ConfigStore>(cs.getPrefix(), cs));
}
