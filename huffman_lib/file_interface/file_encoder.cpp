//
// Created by fr0streaper on 05/10/18.
//

#include "file_encoder.h"

counter get_frequency_data(std::string const& filename) noexcept
{
    counter result;
    file_reader reader(filename);

    std::vector<symbol> current_segment;
    while (!reader.eof())
    {
        if (current_segment.size() == BUFFER_SIZE)
        {
            result.update(current_segment);
            current_segment.clear();
        }
        current_segment.push_back(reader.read());
    }

    result.update(current_segment);
    return result;
}

void write_encoded_data(compressed_data_t const& data, file_writer& writer)
{
    writer.write_uint16_t(static_cast<uint16_t>(data.first.size()));
    writer.write_uint16_t(static_cast<uint16_t>(data.second));

    for (symbol s : data.first)
    {
        writer.write(s);
    }
}

void file_encode(std::string const& src, std::string const& dst)
{
    try
    {
        file_reader reader(src);
    }
    catch (...)
    {
        throw std::runtime_error("Runtime error: unable to open the file " + src);
    }

    encoder e(get_frequency_data(src));
    file_reader reader(src);
    file_writer writer(dst);

    tree_data_t tree_data = e.get_tree_data();

    writer.write_uint16_t(tree_data.second.size());
    for (symbol s : tree_data.second)
    {
        writer.write(s);
    }

    writer.write_uint16_t(tree_data.first.first.size());
    writer.write_uint16_t(tree_data.first.second);
    for (symbol s : tree_data.first.first)
    {
        writer.write(s);
    }

    std::vector<symbol> current_segment;
    while (!reader.eof())
    {
        if (current_segment.size())
        {
            write_encoded_data(e.encode(current_segment), writer);
            current_segment.clear();
        }
        current_segment.push_back(reader.read());
    }

    if (!current_segment.empty())
    {
        write_encoded_data(e.encode(current_segment), writer);
    }
}