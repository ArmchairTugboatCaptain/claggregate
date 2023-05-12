cmake_minimum_required(VERSION 3.16)

project(claggregate VERSION 0.1)

OPTION(RUN_TESTS "Enable and run unit tests." ON)

if(RUN_TESTS)
    message("-- Testing enabled")
    add_subdirectory(tests)
else()
    message("-- Testing disabled")
endif()