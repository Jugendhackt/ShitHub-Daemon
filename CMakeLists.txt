cmake_minimum_required(VERSION 3.9)
project(ShitHubDaemon)

set(CMAKE_CXX_STANDARD 11)
find_package(Boost 1.57.0 COMPONENTS system filesystem REQUIRED)
if(Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
    include_directories(${Boost_INCLUDE_DIRS})
endif()

add_executable(ShitHubDaemon
        src/Server/server.cpp
        src/Server/server.hpp
        src/Server/ipc_connection.cpp
        src/Server/ipc_connection.hpp
        main.cpp
        src/Config/ConfigStore.hpp
        src/Config/ConfigStore.cpp
        src/Config/ConfigManager.hpp
        src/Config/ConfigManager.cpp)

if(Boost_FOUND)
    target_link_libraries(ShitHubDaemon ${Boost_LIBRARIES})
endif()