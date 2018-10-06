//
// Created by fr0streaper on 05/10/18.
//

#include "counter.h"

counter::counter()
{
    for (size_t i = 0; i < ALPHABET_SIZE; ++i)
    {
        cnt[i] = 0;
    }
}

void counter::update(std::vector<symbol> const& data)
{
    for (symbol s : data)
    {
        ++cnt[s];
    }
}

uint64_t counter::get(size_t ind) const
{
    return cnt[ind];
}