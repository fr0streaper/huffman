//
// Created by fr0streaper on 05/10/18.
//

#ifndef HUFFMAN_ENCODER_H
#define HUFFMAN_ENCODER_H

#include "../basic_structure/counter.h"
#include "../consts.h"
#include "../basic_structure/tree.h"

#include <vector>

struct encoder
{
    encoder() = delete;
    encoder(counter const& cnt) : t(cnt) {}

    compressed_data_t encode(std::vector<symbol> const& data);

    tree_data_t get_tree_data();

private:
    tree t;
};

#endif //HUFFMAN_ENCODER_H
