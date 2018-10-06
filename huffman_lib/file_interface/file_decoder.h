//
// Created by fr0streaper on 05/10/18.
//

#ifndef HUFFMAN_FILE_DECODER_H
#define HUFFMAN_FILE_DECODER_H

#include "file_reader.h"
#include "file_writer.h"
#include "../data_interface/decoder.h"

tree_data_t get_tree_data(file_reader& reader);

void write_decoded_data(std::vector<symbol> const& data, file_writer& writer);

void file_decode(std::string const& src, std::string const& dst);

#endif //HUFFMAN_FILE_DECODER_H
