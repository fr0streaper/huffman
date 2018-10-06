//
// Created by fr0streaper on 05/10/18.
//

#include <stdexcept>
#include "decoder.h"

void decoder::initialize_decoder(tree_data_t const &tree_data)
{
    t = tree(tree_data);
    initialized = true;
}

std::vector<symbol> decoder::decode(compressed_data_t const &data) const
{
    if (!initialized)
    {
        throw std::runtime_error("Runtime error: decoder has not been initialized");
    }

    tree::tree_node* current_node = t.root;
    std::vector<symbol> decoding;

    for (size_t i = 0; i < data.first.size(); ++i)
    {
        symbol s = data.first[i];
        for (size_t j = 0; j < 8; ++j)
        {
            bool direction = static_cast<bool>(s & (1 << j));
            if (!direction)
            {
                current_node = current_node->left;
            }
            else
            {
                current_node = current_node->right;
            }

            if (current_node->value != NONE)
            {
                decoding.push_back(static_cast<symbol>(current_node->value));
                current_node = t.root;
            }
        }
    }

    decoding.erase(decoding.begin() + data.second, decoding.end());
    return decoding;
}