cmake_minimum_required(VERSION 2.8.3)
project(mini-yaml)

# C++ compile flags
# -std=c++11 -> for c++ standarts
# -Wall for WARNING
# -pedantic -> for warning between c and c++
# -pthread for portability
# -g -O0 -fprofile-arcs -ftest-coverage for code coverage
if(NOT CMAKE_VERSION VERSION_LESS 3.1)
    set(CMAKE_CXX_STANDARD 11)
    #    set(CMAKE_C_STANDARD 99)
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    #    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")
endif()
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -pthread -g -O0 -fprofile-arcs -ftest-coverage")
# Build warning with -pedantic https://github.com/ros/rosconsole/issues/9
# example how to set c++ compiler flags for GNU
message(STATUS CMAKE_BUILD_TYPE= ${CMAKE_BUILD_TYPE})
if( NOT CMAKE_BUILD_TYPE )
    set(CMAKE_BUILD_TYPE Release)
endif()

if( CMAKE_BUILD_TYPE MATCHES Release )

endif()
if( CMAKE_BUILD_TYPE MATCHES Debug )
    if(CMAKE_CXX_COMPILER_ID MATCHES GNU)

        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-unknown-pragmas -Wno-sign-compare -Woverloaded-virtual -Wwrite-strings -Wno-unused")
        set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g3")
        set(CMAKE_CXX_FLAGS_RELEASE "-O3")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -g -O0 -fprofile-arcs -ftest-coverage")
    endif()
endif()

# Set variables
include(${CMAKE_SOURCE_DIR}/cmake/SetEnv.cmake)

# Library sources
#set(LIBRARY_FOLDER ${PROJECT_NAME})
#set(LIBRARY_NAME ${PROJECT_NAME})
add_subdirectory(${PROJECT_NAME})
message(STATUS "${PROJECT_NAME_LOWERCASE} " ${PROJECT_NAME_LOWERCASE})


# Install targets
include(${CMAKE_SOURCE_DIR}/cmake/InstallConfig.cmake)