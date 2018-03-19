//
// Created by anghenfil on 13.02.18.
//

#include <fstream>
#include "ConfigStore.hpp"
#include "../Utils/Filepaths.hpp"
#include "../Log/Log.hpp"
#include "../Utils/Split.hpp"

Config::ConfigStore::ConfigStore(const std::string& filepath, const std::string& templatepath) {
    failbit = false;

    if(Utils::Filepaths::checkPath(filepath) && Utils::Filepaths::checkPath(templatepath)) {
        this->filepath = filepath;
        this->templatepath = templatepath;

        loadValues();
    }else{
        failbit = true;

        std::string msg = "Config::ConfigStore::ConfigStore filepath or templatepath invalid.";
        Log::Log::print(Log::Levels::CRITICAL, msg);
    }
}

bool Config::ConfigStore::loadValues() {
    if(!failbit){
        std::ifstream ifs;
        ifs.exceptions(std::ifstream::failbit | std::ifstream::badbit);

        try{
            ifs.open(filepath, std::ifstream::in);

            std::string line;
            while(ifs.good()){
                std::getline(ifs, line);
                processLine(line);
            }
        }catch(std::ifstream::failure& e){
            std::string msg = "Coudln't read configfile "+filepath;
            Log::Log::print(Log::Levels::ERROR, msg, e);
        }
        ifs.close();
        return true;
    }
    return false;
}

bool Config::ConfigStore::processLine(std::string &line) {
    if(!line.empty()){ //Only proceed if line is not empty
        int pos = 0;
        for(int i=0;i<line.size();i++){
            if(!isblank(line[i])){
                pos = i;
                break;
            }
        }
        if(line[pos] != '#') { //Ignore line if it begins with #
            const char splch = '='; //Split by '='
            std::vector<std::string> brackets = Utils::Split::split(line, &splch);

            if (brackets.size() == 2) {
                //TODO: Lookup in config template, allow different types
                values.insert(std::pair<std::string, std::string>(brackets[0], brackets[1]));

                std::string tracestring = "Config::ConfigStore::processLine inserted "+brackets[0]+" - "+brackets[1];
                Log::Log::print(Log::Levels::TRACE, tracestring);
            } else {
                std::string msg = "Invalid Configline: " + line;
                Log::Log::print(Log::Levels::WARN, msg);
            }
        }
    }else{
        return false;
    }
}
