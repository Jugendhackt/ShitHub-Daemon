//
// Created by anghenfil on 23.02.18.
//

#include <iostream>
#include "Log.hpp"
#include <string>

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

bool Log::Log::print(Levels level, std::string &msg, std::exception &excep) {
    std::string test = msg+" "+excep.what();
    print(level, test);
    return false;
}

bool Log::Log::print(Levels level, std::string &msg) {
    if(level & Levels::CRITICAL){
        for (auto &i : critical) {
            i->action(msg);
        }
    }else if(level & Levels::WARN){
        for (auto &i : warn) {
            i->action(msg);
        }
    }else if(level & Levels::ERROR){
        for (auto &i : error) {
            i->action(msg);
        }
    }else if(level & Levels::INFO){
        for (auto &i : info) {
            i->action(msg);
        }
    }else if(level & Levels::DEBUG){
        for (auto &i : debug) {
            i->action(msg);
        }
    }else if(level & Levels::TRACE){
        for (auto &i : trace) {
            i->action(msg);
        }
    }
    return false;
}
