cmake_minimum_required(VERSION 3.16)

add_executable(roster_test_suite roster_test.cpp ${CMAKE_SOURCE_DIR}/src/Roster.cpp ${CMAKE_SOURCE_DIR}/src/Utilities.cpp)

target_include_directories(roster_test_suite PUBLIC ${CMAKE_SOURCE_DIR}/src)

add_test(NAME RosterTestSuite COMMAND roster_test_suite)