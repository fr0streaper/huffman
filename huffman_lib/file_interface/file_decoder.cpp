//
// Created by fr0streaper on 05/10/18.
//

#include "file_decoder.h"


void write_decoded_data(std::vector<symbol> const& data, file_writer& writer)
{
    for (symbol s : data)
    {
        writer.write(s);
    }
}

void file_decode(std::string const& src, std::string const& dst)
{
    try
    {
        file_reader reader(src);
    }
    catch (...)
    {
        throw std::runtime_error("Runtime error: unable to open the file " + src);
    }

    file_reader reader(src);
    file_writer writer(dst);

    tree_data_t tree_data;
    try
    {
        size_t symbols_length = reader.read_uint16_t();
        tree_data.second.resize(symbols_length);
        for (size_t i = 0; i < symbols_length; ++i)
        {
            tree_data.second[i] = reader.read();
        }

        size_t traversal_length = reader.read_uint16_t();
        tree_data.first.second = reader.read_uint16_t();
        tree_data.first.first.resize(traversal_length);
        for (size_t i = 0; i < traversal_length; ++i)
        {
            tree_data.first.first[i] = reader.read();
        }
    }
    catch (...)
    {
        throw std::runtime_error("Runtime error: insufficient tree data");
    }

    decoder d;
    try
    {
        d.initialize_decoder(tree_data);
    }
    catch (...)
    {
        throw std::runtime_error("Runtime error: invalid decoding data");
    }

    std::vector<symbol> current_segment;
    while (!reader.eof())
    {
        try
        {
            size_t compressed_data_size = reader.read_uint16_t();
            size_t compressed_data_symbols = reader.read_uint16_t();

            current_segment.resize(compressed_data_size);
            for (size_t i = 0; i < compressed_data_size; ++i)
            {
                current_segment[i] = reader.read();
            }

            write_decoded_data(d.decode({ current_segment, compressed_data_symbols }), writer);
        }
        catch (...)
        {
            throw std::runtime_error("Runtime error: decoding failed");
        }
    }
}