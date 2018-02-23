//
// Created by anghenfil on 11.01.18.
//

#ifndef SHITHUBDAEMON_CONFIGSTORE_HPP
#define SHITHUBDAEMON_CONFIGSTORE_HPP

#include <string>
#include <map>
#include <boost/any.hpp>

namespace Config {
    class ConfigStore {
    private:
        std::string prefix; //Prefix of configstore (unique); For example "main" or "database"
        std::string filepath;
        std::string templatepath;
        std::map<std::string, boost::any> values; //Key-Value

        //Method for loading values:
        bool loadValues(); //TODO: Return Error Class with Error Message etc.
        bool checkValues(); //TODO: Return Error Class with Error Message etc.

    public:
        ConfigStore(const std::string &,
                    const std::string &); //Construct configstore from configfile, checks Config values
    };
}

#endif //SHITHUBDAEMON_CONFIGSTORE_HPP
