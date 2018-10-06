//
// Created by fr0streaper on 05/10/18.
//

#ifndef HUFFMAN_COUNTER_H
#define HUFFMAN_COUNTER_H

#include "../consts.h"

#include <vector>
#include <cstdint>

struct counter
{
    counter();

    void update(std::vector<symbol> const& data);

    uint64_t get(size_t ind) const;

private:
    uint64_t cnt[ALPHABET_SIZE];
};

#endif //HUFFMAN_COUNTER_H
