//
// Created by fr0streaper on 05/10/18.
//

#ifndef HUFFMAN_FILE_READER_H
#define HUFFMAN_FILE_READER_H

#include <string>
#include <fstream>
#include "../consts.h"

struct file_reader
{
    file_reader() = delete;
    file_reader(std::string const& _filename);

    ~file_reader();

    bool eof();

    symbol read();

    uint16_t read_uint16_t();

private:

    std::ifstream reader;
    std::string filename;
    char buffer[BUFFER_SIZE];
    size_t current_ind, end_ind;
};

#endif //HUFFMAN_FILE_READER_H
