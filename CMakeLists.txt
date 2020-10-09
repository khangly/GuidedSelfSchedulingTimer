cmake_minimum_required(VERSION 3.16)
project(guided_self_scheduling)

set(CMAKE_CXX_STANDARD 17)

add_executable(guided_self_scheduling main.cpp GuidedSelfScheduling.cpp GuidedSelfScheduling.h)