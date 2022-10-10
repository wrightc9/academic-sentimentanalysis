cmake_minimum_required(VERSION 3.10)
project(SentimentAnalysis)

set(CMAKE_CXX_STANDARD 14)

add_executable(SentimentAnalysis main.cpp database.cpp database.h record.cpp record.h)