//
// Created by anghenfil on 11.01.18.
//
#ifndef SHITHUBDAEMON_CONFIG_MANAGER_HPP
#define SHITHUBDAEMON_CONFIG_MANAGER_HPP

#include "configstore.hpp"

class config_manager{
private:
    static configstore cs;
public:
    config_manager();

    //Load configuration from file
    static bool create_config_cash();

    //Get methods for different data types
    static std::string get(std::string);
    static int get_int(std::string);
    static double get_double(std::string);
    static bool get_bool(std::string);
    static char get_char(std::string);
};
#endif //SHITHUBDAEMON_CONFIG_MANAGER_HPP
