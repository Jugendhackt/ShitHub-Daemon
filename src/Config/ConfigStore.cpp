//
// Created by anghenfil on 13.02.18.
//

#include <fstream>
#include "ConfigStore.hpp"
#include "../Utils/Filepaths.hpp"
#include "../Log/Log.hpp"

Config::ConfigStore::ConfigStore(const std::string& filepath, const std::string& templatepath) {
    failbit = false;

    if(Utils::Filepaths::checkPath(filepath)) {
        this->filepath = filepath;
    }else{
        failbit = true;
    }
    if(Utils::Filepaths::checkPath(templatepath)) {
        this->templatepath = templatepath;
    }else{
        failbit = true;
    }
}

bool Config::ConfigStore::loadValues() {
    if(!failbit){
        std::ifstream ifs;
        ifs.exceptions(std::ifstream::failbit | std::ifstream::badbit);

        try{
            std::string line;
            while(std::getline(ifs, line)){
                processLine(line);
            }
        }catch(std::ifstream::failure& e){
            std::string msg = "Coudln't read configfile "+filepath;
            Log::Log::print(Log::Levels::ERROR, msg, e);
        }
        return true;
    }
    return false;
}

bool Config::ConfigStore::processLine(std::string &line) {

    return false;
}
