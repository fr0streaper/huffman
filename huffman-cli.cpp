
#include "huffman_lib/huffman.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc == 2)
    {
        string const mode = argv[1];
        if (mode == "--help")
        {
            cerr << "Huffman encoder/decoder v1.0\n";
            cerr << "Usage: huffman [-c|-d] <source> <destination> | huffman -f\n";
            cerr << "-c : encode source to destination\n";
            cerr << "-d : decode source to destination\n";
            cerr << "-f : pay respects\n";
        }
        else if (mode == "-f")
        {
            cerr << "Respects have been paid\n";
        }
        else
        {
            cerr << "Invalid usage; Refer to huffman --help\n";
        }
        return 0;
    }
    if (argc != 4)
    {
        cerr << "Invalid usage; Refer to huffman --help\n";
        return 0;
    }

    string const mode = argv[1];
    string const src = argv[2];
    string const dst = argv[3];

    uint64_t start_clock, end_clock;
    if (mode == "-c")
    {
        cerr << "Encoding " << src << " to " << dst << "\n";
        start_clock = clock();

        try
        {
            huffman_encode_file(src, dst);
        }
        catch (std::runtime_error const e)
        {
            cerr << "Encoding failed due to: \n" << e.what() << "\n";
            return 0;
        }

        end_clock = clock();
        cerr << "Encoding finished in " << static_cast<double>(end_clock - start_clock) / CLOCKS_PER_SEC << " seconds\n";
    }
    else if (mode == "-d")
    {
        cerr << "Decoding " << src << " to " << dst << "\n";
        start_clock = clock();

        try
        {
            huffman_decode_file(src, dst);
        }
        catch (std::runtime_error const e)
        {
            cerr << "Decoding failed due to: \n" << e.what() << "\n";
            return 0;
        }

        end_clock = clock();
        cerr << "Decoding finished in " << static_cast<double>(end_clock - start_clock) / CLOCKS_PER_SEC << " seconds\n";
    }
    else
    {
        cerr << "Invalid usage; Refer to huffman --help\n";
    }

    return 0;
}