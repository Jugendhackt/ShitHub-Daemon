//
// Created by anghenfil on 23.02.18.
//

#ifndef SHITHUBDAEMON_LEVELS_HPP
#define SHITHUBDAEMON_LEVELS_HPP

namespace Log{
    enum Levels{
        TRACE = 0x01,
        DEBUG = 0x02,
        INFO = 0x03,
        WARN = 0x04,
        ERROR = 0x05,
        CRITICAL = 0x06,
        NONE = 0x07
    };
}

#endif //SHITHUBDAEMON_LEVELS_HPP
