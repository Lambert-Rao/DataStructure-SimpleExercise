cmake_minimum_required(VERSION 3.0)

project(DS_Exercise)

set(CMAKE_CXX_STANDARD 20)

aux_source_directory(. DIR_SRCS)

add_executable(DS_Exercise ${DIR_SRCS})