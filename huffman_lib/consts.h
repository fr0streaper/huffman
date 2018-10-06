//
// Created by fr0streaper on 05/10/18.
//

#ifndef HUFFMAN_CONSTS_H
#define HUFFMAN_CONSTS_H

#include <cstdio>
#include <cstdint>
#include <vector>

typedef unsigned char symbol;
typedef std::pair<std::pair<std::vector<symbol>, uint16_t>, std::vector<symbol> > tree_data_t;
typedef std::pair<std::vector<symbol>, uint16_t> compressed_data_t;

const size_t BUFFER_SIZE = 256 * 256;
const size_t ALPHABET_SIZE = 256;
const uint16_t NONE = 666;

#endif //HUFFMAN_CONSTS_H
