//
// Created by fr0streaper on 05/10/18.
//

#ifndef HUFFMAN_FILE_WRITER_H
#define HUFFMAN_FILE_WRITER_H

#include <string>
#include <fstream>
#include "../consts.h"

struct file_writer
{
    file_writer() = delete;
    file_writer(std::string const& _filename);

    ~file_writer();

    void write(symbol const s);

    void write_uint16_t(uint16_t const x);

private:

    std::ofstream writer;
    char buffer[BUFFER_SIZE];
    size_t current_ind;
};

#endif //HUFFMAN_FILE_WRITER_H
