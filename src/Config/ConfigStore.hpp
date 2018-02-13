//
// Created by anghenfil on 11.01.18.
//

#ifndef SHITHUBDAEMON_CONFIGSTORE_HPP
#define SHITHUBDAEMON_CONFIGSTORE_HPP

#include <string>
#include <map>

class ConfigStore{
private:
    std::string prefix; //Prefix of configstore (unique); For example "main" or "database"

    template <class T>
    std::map<std::string, T> values; //Key-Value

    //Method for loading values:
    bool loadValues(); //TODO: Return Error Class with Error Message etc.
    bool checkValues(); //TODO: Return Error Class with Error Message etc.
    
public:
    ConfigStore(std::string filename); //Construct configstore from configfile, checks Config values
};

#endif //SHITHUBDAEMON_CONFIGSTORE_HPP
