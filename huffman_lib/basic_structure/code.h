//
// Created by fr0streaper on 05/10/18.
//

#ifndef HUFFMAN_CODE_H
#define HUFFMAN_CODE_H

#include <cstdint>
#include <cstdio>

struct code
{
    uint64_t value;
    size_t length;

    code() : value(0), length(0) {}
    code(uint64_t _value, size_t _length) : value(_value), length(_length) {}

    void push_bit(bool val);

    void pop_bit();

    bool operator[](size_t ind) const;

    void clear();
};

#endif //HUFFMAN_CODE_H
