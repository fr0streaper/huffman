//
// Created by fr0streaper on 05/10/18.
//

#include "encoder.h"

compressed_data_t encoder::encode(std::vector<symbol> const& data)
{
    std::vector<uint64_t> preliminary_encoding(data.size(), 0);
    size_t current_ind = 0;

    for (symbol s : data)
    {
        code c = t.codes[s];

        preliminary_encoding[current_ind / 64] |= (c.value << (current_ind % 64));
        size_t written = std::min(64 - (current_ind % 64), c.length);

        current_ind += written;
        preliminary_encoding[current_ind / 64] |= (c.value >> written);

        current_ind += c.length - written;
    }
    preliminary_encoding.resize((current_ind / 64) + static_cast<size_t>((current_ind % 64) != 0));

    std::vector<symbol> encoding(8 * preliminary_encoding.size());
    for (size_t i = 0; i < preliminary_encoding.size(); ++i)
    {
        for (size_t j = 0; j < 8; ++j)
        {
            encoding[i * 8 + j] = static_cast<symbol>((preliminary_encoding[i] >> (8 * j)) & 0xFF);
        }
    }
    encoding.resize((current_ind / 8) + static_cast<size_t>((current_ind % 8) != 0));

    return { encoding, data.size() };
}

tree_data_t encoder::get_tree_data()
{
    return t.get_traversal();
}