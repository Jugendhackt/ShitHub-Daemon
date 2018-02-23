//
// Created by anghenfil on 23.02.18.
//

#ifndef SHITHUBDAEMON_HANDLER_HPP
#define SHITHUBDAEMON_HANDLER_HPP

#include "Levels.hpp"
#include <string>

namespace Log {
    class Handler {
    public:
        virtual bool action(std::string&)= 0;
        virtual bool action(std::string&, std::exception&)= 0;
    };
}

#endif //SHITHUBDAEMON_HANDLER_HPP
