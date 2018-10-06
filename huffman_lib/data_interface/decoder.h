//
// Created by fr0streaper on 05/10/18.
//

#ifndef HUFFMAN_DECODER_H
#define HUFFMAN_DECODER_H

#include "../basic_structure/tree.h"

struct decoder
{

    decoder() : t(), initialized(false) {}

    void initialize_decoder(tree_data_t const& tree_data);

    std::vector<symbol> decode(compressed_data_t const& data) const;

private:
    tree t;
    bool initialized;
};

#endif //HUFFMAN_DECODER_H
