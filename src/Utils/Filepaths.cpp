//
// Created by anghenfil on 22.02.18.
//

#include "Filepaths.hpp"
#include <fstream>

bool Utils::Filepaths::checkPath(const std::string& path) {
        std::ifstream testfile;
        testfile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

        try{
            testfile.open(path);
        }catch(std::ifstream::failure& e){
            return false;
        }
        return true;
}
