//
// Created by fr0streaper on 05/10/18.
//

#include "file_reader.h"

file_reader::file_reader(std::string const& _filename)
{
    reader.open(_filename, std::ifstream::binary);
    filename = _filename;
    current_ind = end_ind = 0;

    if (reader.fail())
    {
        reader.close();
        throw std::runtime_error("Runtime error: unable to open the file");
    }
}

file_reader::~file_reader()
{
    reader.close();
}

bool file_reader::eof()
{
    return (current_ind == end_ind) && (reader.peek() == EOF);
}

symbol file_reader::read()
{
    if (current_ind == end_ind)
    {
        reader.read(buffer, BUFFER_SIZE);
        end_ind = reader.gcount();
        current_ind = 0;
    }
    return static_cast<symbol>(buffer[current_ind++]);
}

uint16_t file_reader::read_uint16_t()
{
    uint16_t result = 0;

    if (eof())
    {
        throw std::runtime_error("Runtime error: insufficient data");
    }

    result += static_cast<uint16_t>(read());
    result <<= 8;

    if (eof())
    {
        throw std::runtime_error("Runtime error: insufficient data");
    }

    result += static_cast<uint16_t>(read());
    return result;
}