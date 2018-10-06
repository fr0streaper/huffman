//
// Created by fr0streaper on 05/10/18.
//

#ifndef HUFFMAN_LIB_H
#define HUFFMAN_LIB_H

#include "consts.h"
#include "data_interface/encoder.h"
#include "data_interface/decoder.h"
#include "file_interface/file_encoder.h"
#include "file_interface/file_decoder.h"

#include <vector>
#include <string>

//compressed_data_t huffman_encode(std::vector<symbol> const& data);

//std::vector<symbol> huffman_decode(compressed_data_t const& data);

void huffman_encode_file(std::string const& input_filename, std::string const& output_filename);

void huffman_decode_file(std::string const& input_filename, std::string const& output_filename);

#endif //HUFFMAN_LIB_H
