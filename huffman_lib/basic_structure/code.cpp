//
// Created by fr0streaper on 05/10/18.
//

#include "code.h"

void code::push_bit(bool val)
{
    value |= ((static_cast<uint64_t>(val)) << length);
    ++length;
}

void code::pop_bit()
{
    --length;
}

bool code::operator[](size_t ind) const
{
    return static_cast<bool>(value & (1ULL << ind));
}

void code::clear()
{
    value = 0;
    length = 0;
}