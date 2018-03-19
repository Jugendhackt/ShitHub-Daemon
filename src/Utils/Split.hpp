//
// Created by anghenfil on 25.02.18.
//

#ifndef SHITHUBDAEMON_SPLIT_HPP
#define SHITHUBDAEMON_SPLIT_HPP
#include <string>
#include <vector>

namespace Utils {
    class Split {
    public:
        static std::vector<std::string> split(std::string &, const char *);
    };
}


#endif //SHITHUBDAEMON_SPLIT_HPP
