//
// Created by anghenfil on 23.02.18.
//

#include "Timestamp.hpp"

std::string Utils::Timestamp::getTimestamp() {
    time_t ltime;
    ltime=time(nullptr);
    return asctime( gmtime(&ltime) );
}
