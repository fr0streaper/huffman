//
// Created by fr0streaper on 05/10/18.
//

#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include "../consts.h"
#include "counter.h"
#include "code.h"

struct tree
{
    struct tree_node
    {
        tree_node *left, *right;
        uint16_t value;

        tree_node() : left(nullptr), right(nullptr), value(NONE) {}
        tree_node(tree_node* _left, tree_node* _right) : left(_left), right(_right), value(NONE) {}
        tree_node(uint16_t _value) : left(nullptr), right(nullptr), value(_value) {}

        ~tree_node()
        {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

    tree_node* root;
    code codes[ALPHABET_SIZE];

    tree();
    tree(counter const& data);
    tree(tree_data_t const& data);

    tree_data_t get_traversal();

    void check_tree(tree_node* v);

private:

    void code_init_dfs(tree_node* v, code current_code);

    void construction_dfs(tree_node* v, std::vector<symbol>& traversal, uint16_t& len, uint16_t& traversal_ind,
                          std::vector<symbol>& symbols, uint16_t& symbols_ind);

    void traversal_dfs(tree_node* v, std::vector<symbol>& traversal, uint16_t& ind, std::vector<symbol>& symbols);

    void go_left(std::vector<symbol>& traversal, uint16_t& ind);
    void go_right(std::vector<symbol>& traversal, uint16_t& ind);

    void invalid_tree() const;
};

#endif //HUFFMAN_TREE_H
