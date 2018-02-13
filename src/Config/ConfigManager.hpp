//
// Created by anghenfil on 11.01.18.
//
#ifndef SHITHUBDAEMON_CONFIG_MANAGER_HPP
#define SHITHUBDAEMON_CONFIG_MANAGER_HPP

#include <string>
#include <map>
#include "ConfigStore.hpp"

class ConfigManager{
private:
    std::map<std::string, ConfigStore> configstores; //Map with configstore and prefix

public:
    ConfigManager();

    //Method for adding ConfigStores to ConfigManager
    bool addConfigStore(ConfigStore);

    //Get method; Resolves prefix to correct configstore
    template <class T>
    T get(std::string);
};
#endif //SHITHUBDAEMON_CONFIG_MANAGER_HPP