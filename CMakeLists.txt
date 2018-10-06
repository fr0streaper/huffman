cmake_minimum_required(VERSION 3.10)
project(huffman)

set(CMAKE_CXX_STANDARD 11)

add_library(huffman_lib
        huffman_lib/huffman.h
        huffman_lib/huffman.cpp
        huffman_lib/data_interface/encoder.h
        huffman_lib/data_interface/encoder.cpp
        huffman_lib/data_interface/decoder.h
        huffman_lib/data_interface/decoder.cpp
        huffman_lib/consts.h
        huffman_lib/basic_structure/tree.h
        huffman_lib/basic_structure/tree.cpp
        huffman_lib/file_interface/file_reader.cpp
        huffman_lib/file_interface/file_reader.h
        huffman_lib/file_interface/file_writer.cpp
        huffman_lib/file_interface/file_writer.h
        huffman_lib/file_interface/file_encoder.cpp
        huffman_lib/file_interface/file_encoder.h
        huffman_lib/file_interface/file_decoder.cpp
        huffman_lib/file_interface/file_decoder.h
        huffman_lib/basic_structure/counter.cpp
        huffman_lib/basic_structure/counter.h
        huffman_lib/basic_structure/code.cpp
        huffman_lib/basic_structure/code.h)

add_executable(huffman
        huffman-cli.cpp)

add_executable(huffman_testing
        gtest/gtest.h
        gtest/gtest-all.cc
        gtest/gtest_main.cc
        huffman_testing.cpp)

target_link_libraries(huffman huffman_lib)
target_link_libraries(huffman_testing huffman_lib -lgmp -lgmpxx -lpthread)