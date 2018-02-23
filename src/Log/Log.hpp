//
// Created by anghenfil on 23.02.18.
//

#ifndef SHITHUBDAEMON_LOG_HPP
#define SHITHUBDAEMON_LOG_HPP

#include <string>
#include "Levels.hpp"
#include "Handler.hpp"
#include <vector>

namespace Log {
    class Log {
    public:
        static bool print(int, std::string&);
        static bool print(int, std::string&, std::exception&);

        static bool addHandler(Levels, Handler&);

    private:
        static std::vector<Handler*> trace;
        static std::vector<Handler*> debug;
        static std::vector<Handler*> info;
        static std::vector<Handler*> warn;
        static std::vector<Handler*> error;
        static std::vector<Handler*> critical;
    };
}


#endif //SHITHUBDAEMON_LOG_HPP
