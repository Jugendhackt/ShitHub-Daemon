cmake_minimum_required(VERSION 3.9)
project(ShitHubDaemon)
include(FindXercesC)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

find_package(Boost 1.54.0 COMPONENTS system filesystem REQUIRED)
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
        src/Config/ConfigManager.cpp
        src/Utils/Filepaths.cpp
        src/Utils/Filepaths.hpp
        src/Log/Log.cpp
        src/Log/Log.hpp
        src/Log/Levels.hpp
        src/Log/Handler.hpp
        src/Log/FileHandler.cpp
        src/Log/FileHandler.hpp
        src/Utils/Timestamp.cpp
        src/Utils/Timestamp.hpp
        src/Utils/Split.cpp
        src/Utils/Split.hpp
        )

if(Boost_FOUND)
    target_link_libraries(ShitHubDaemon ${Boost_LIBRARIES})
endif()

find_package(XercesC REQUIRED)
include_directories( ${XercesC_INCLUDE_DIR} )
target_link_libraries ( ${PROJECT_NAME} ${XercesC_LIBRARY} )
