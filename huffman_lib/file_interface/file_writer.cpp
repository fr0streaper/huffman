//
// Created by fr0streaper on 05/10/18.
//

#include "file_writer.h"

file_writer::file_writer(std::string const& _filename)
{
    writer.open(_filename, std::ofstream::binary);
    current_ind = 0;
}

file_writer::~file_writer()
{
    writer.write(buffer, current_ind);
    writer.close();
}

void file_writer::write(symbol const s)
{
    if (current_ind == BUFFER_SIZE)
    {
        writer.write(buffer, current_ind);
        current_ind = 0;
    }
    buffer[current_ind++] = static_cast<char>(s);
}

void file_writer::write_uint16_t(uint16_t const x)
{
    write(static_cast<symbol>(x >> 8));
    write(static_cast<symbol>(x & 0xFF));
}