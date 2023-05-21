cmake_minimum_required(VERSION 3.20)
project(ch6)
set(CMAKE_CXX_STANDARD 11)
add_executable(test_urls test_urls.cpp urls.cpp)
add_executable(test_palindrome test_palindrome.cpp)
add_executable(test_vcat test_vcat.cpp split.cpp char_pic.cpp)
add_executable(report report.cpp Student_info.cpp grade.cpp split.cpp analysis.cpp)

