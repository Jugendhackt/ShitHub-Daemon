//
// Created by anghenfil on 23.02.18.
//

#include <iostream>
#include "Log.hpp"
#include <string>

bool Log::Log::print(int, std::string &, std::exception&) {
    return false;
}

bool Log::Log::print(int, std::string &) {
    return false;
}

std::vector<Log::Handler*> Log::Log::critical = {};
std::vector<Log::Handler*> Log::Log::warn = {};
std::vector<Log::Handler*> Log::Log::error = {};
std::vector<Log::Handler*> Log::Log::debug = {};
std::vector<Log::Handler*> Log::Log::trace = {};
std::vector<Log::Handler*> Log::Log::info = {};

bool Log::Log::addHandler(Levels level, Handler &handler) {
    if (level & Levels::CRITICAL) {
        critical.push_back(&handler);
    }
    if (level & Levels::ERROR) {
        error.push_back(&handler);
    }
    if (level & Levels::WARN) {
         warn.push_back(&handler);
    }
    if (level & Levels::INFO) {
        info.push_back(&handler);
    }
    if (level & Levels::DEBUG) {
        debug.push_back(&handler);
    }
    if (level & Levels::TRACE) {
        trace.push_back(&handler);
    }

    return true;
}