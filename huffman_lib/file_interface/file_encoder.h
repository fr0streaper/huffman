//
// Created by fr0streaper on 05/10/18.
//

#ifndef HUFFMAN_FILE_ENCODER_H
#define HUFFMAN_FILE_ENCODER_H

#include "file_reader.h"
#include "file_writer.h"
#include "../data_interface/encoder.h"

counter get_frequency_data(std::string const& filename) noexcept;

void write_encoded_data(compressed_data_t const& data, file_writer& writer);

void file_encode(std::string const& src, std::string const& dst);

#endif //HUFFMAN_FILE_ENCODER_H
