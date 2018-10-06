//
// Created by fr0streaper on 05/10/18.
//

#include "huffman.h"

void huffman_encode_file(std::string const& src, std::string const& dst)
{
    file_encode(src, dst);
}

void huffman_decode_file(std::string const& src, std::string const& dst)
{
    file_decode(src, dst);
}
