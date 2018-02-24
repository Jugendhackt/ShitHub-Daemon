//
// Created by anghenfil on 23.02.18.
//

#ifndef SHITHUBDAEMON_FILEHANDLER_HPP
#define SHITHUBDAEMON_FILEHANDLER_HPP

#include "Handler.hpp"

namespace Log {
    class FileHandler : public Handler {
    public:
        bool badstate = false;

        explicit FileHandler(std::string&);
        bool action(std::string&) override;
    private:
        std::string path;
    };
}

#endif //SHITHUBDAEMON_FILEHANDLER_HPP
