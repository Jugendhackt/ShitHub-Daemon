//
// Created by anghenfil on 23.02.18.
//

#include <fstream>
#include <iostream>
#include "FileHandler.hpp"
#include "../Utils/Filepaths.hpp"
#include "../Utils/Timestamp.hpp"

bool Log::FileHandler::action(std::string &msg) {
    std::ofstream ofs(path, std::ofstream::app);
    ofs << Utils::Timestamp::getTimestamp()<<msg<<std::endl;
    return false;
}

Log::FileHandler::FileHandler(std::string& tpath){
    path = tpath;
}
