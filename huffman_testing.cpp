//
// Created by fr0streaper on 05/10/18.
//

#include "gtest/gtest.h"
#include "huffman_lib/huffman.h"

namespace
{
    std::string encode_and_decode(std::string str)
    {
        std::ofstream test_input("test.txt", std::ofstream::binary);
        test_input << str;
        test_input.close();

        huffman_encode_file("test.txt", "test-e.huff");
        huffman_decode_file("test-e.huff", "test-ed.txt");

        std::ifstream test_output("test-ed.txt", std::ifstream::binary);
        std::string result((std::istreambuf_iterator<char>(test_output)), std::istreambuf_iterator<char>());
        test_output.close();

        return result;
    }

    bool compare_files(std::string expected, std::string actual)
    {
        std::ifstream expected_input(expected, std::ifstream::binary),
                actual_input(actual, std::ifstream::binary);

        char expected_buffer[BUFFER_SIZE], actual_buffer[BUFFER_SIZE];
        while (!expected_input.eof() && !actual_input.eof())
        {
            expected_input.read(expected_buffer, BUFFER_SIZE);
            actual_input.read(actual_buffer, BUFFER_SIZE);

            if (expected_buffer != actual_buffer)
            {
                return false;
            }
        }

        return true;
    }
}

TEST(correctness, hello_world)
{
    std::string input = "konnichiwa sekai";
    std::string output = encode_and_decode(input);
    EXPECT_EQ(input, output);
}

TEST(correctness, empty)
{
    std::string input = "";
    std::string output = encode_and_decode(input);
    EXPECT_EQ(input, output);
}

//TODO: fix large tests

/*
TEST(correctness, pictures)
{
    for (char i = '1'; i <= '5'; ++i)
    {
        std::string name = "test";
        name += i;

        huffman_encode_file(name + ".jpg", "test-e.huff");
        huffman_decode_file("test-e.huff", name + "-ed.jpg");

        EXPECT_TRUE(compare_files(name + ".jpg", name + "-ed.jpg"));
    }


    huffman_encode_file("test1.jpg", "test-e.huff");
    huffman_decode_file("test-e.huff", "test1-ed.jpg");

    EXPECT_TRUE(compare_files("test.jpg", "test1-ed.jpg"));
}
*/