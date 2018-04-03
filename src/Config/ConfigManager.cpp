//
// Created by anghenfil on 11.01.18.
//

#include "ConfigManager.hpp"
#include "../Utils/Split.hpp"
#include "../Log/Log.hpp"

Config::ConfigManager::ConfigManager() : configstores(){}

void Config::ConfigManager::addConfigStore(Config::ConfigStore cs) {
    configstores.insert(std::pair<std::string, Config::ConfigStore>(cs.getPrefix(), cs));
}

template<class T>
T Config::ConfigManager::get(std::string key) {
    //Split and check prefix to identify config
    std::vector<std::string> keys = Utils::Split::split(key, reinterpret_cast<const char *>(':'));
    std::string prefix;
    std::string newkey;

    if(keys.size() < 2){
        std::string error = "Config::ConfigManager::get "+key+" is invalid key and can't be splitted valid.";
        Log::Log::print(Log::ERROR, error);
        return false;
    }else {
        prefix = keys[0];
        keys.erase(keys.begin()); //Remove prefix from keys array
        for (auto const i : keys) { //Combine rest from keys array to the new key
            newkey += i;
        }
        //TODO: Trace

        //Try to get ConfigStore with specified prefix
        try{
            boost::any_cast<T>(configstores.at(prefix).get(newkey));
        }catch(std::out_of_range& e){
            std::string error = "Config::ConfigManager::get Config "+prefix+": "+newkey+" doesn't exist.";
            Log::Log::print(Log::ERROR, error, e);
            return false;
        }catch(boost::bad_any_cast &e){
            std::string error = "Config::ConfigManager::get Config "+prefix+": "+newkey+" can't casted.";
            Log::Log::print(Log::ERROR, error, e);
            return false;
        }
    }
}
