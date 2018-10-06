//
// Created by fr0streaper on 05/10/18.
//

#include "tree.h"

#include <set>
#include <utility>
#include <stdexcept>

tree::tree()
{
    root = nullptr;
}

tree::tree(counter const& data)
{
    std::set<std::pair<uint64_t, tree_node*> > vertices;

    for (uint16_t i = 0; i < ALPHABET_SIZE; ++i)
    {
        if (data.get(i))
        {
            vertices.insert({ data.get(i), new tree_node(i) });
        }
    }

    if (vertices.size() == 1)
    {
        vertices.insert({ vertices.begin()->first, new tree_node() });
    }

    if (vertices.empty())
    {
        vertices.insert({ 0, nullptr });
    }

    while (vertices.size() > 1)
    {
        uint64_t total = vertices.begin()->first;
        tree_node* left = vertices.begin()->second;
        vertices.erase(vertices.begin());

        total += vertices.begin()->first;
        tree_node* right = vertices.begin()->second;
        vertices.erase(vertices.begin());

        vertices.insert({ total, new tree_node(left, right) });
    }

    root = vertices.begin()->second;

    code_init_dfs(root, code());
}

tree::tree(tree_data_t const& data)
{
    std::vector<symbol> traversal = data.first.first, symbols = data.second;
    uint16_t len = data.first.second;

    if (symbols.empty())
    {
        root = nullptr;
        return;
    }

    root = new tree_node();
    uint16_t traversal_ind = 0, symbols_ind = 0;
    construction_dfs(root, traversal, len, traversal_ind, symbols, symbols_ind);
    check_tree(root);
}

tree_data_t tree::get_traversal()
{
    std::vector<symbol> traversal, symbols;
    uint16_t len = 0;

    traversal_dfs(root, traversal, len, symbols);
    return { { traversal, len }, symbols };
}

void tree::code_init_dfs(tree_node* v, code current_code)
{
    if (v == nullptr)
    {
        return;
    }

    if (v->value != NONE)
    {
        codes[v->value] = current_code;
        return;
    }

    if ((v->left == nullptr) != (v->right == nullptr))
    {
        invalid_tree();
    }

    current_code.push_bit(false);
    code_init_dfs(v->left, current_code);
    current_code.pop_bit();

    current_code.push_bit(true);
    code_init_dfs(v->right, current_code);
    current_code.pop_bit();
}

void tree::check_tree(tree_node* v)
{
    if ((v->left == nullptr) != (v->right == nullptr))
    {
        invalid_tree();
    }

    if (v->left != nullptr)
    {
        check_tree(v->left);
        check_tree(v->right);
    }
}

void tree::construction_dfs(tree_node* v, std::vector<symbol>& traversal, uint16_t& len, uint16_t& traversal_ind,
                            std::vector<symbol>& symbols, uint16_t& symbols_ind)
{
    bool current_direction = false;
    if (traversal_ind < len)
    {
        current_direction = static_cast<bool>(traversal[traversal_ind / 8] & (1 << (traversal_ind % 8)));
    }
    if (current_direction)
    {
        v->left = new tree_node();
        construction_dfs(v->left, traversal, len, ++traversal_ind, symbols, symbols_ind);

        if (traversal_ind < len)
        {
            current_direction = static_cast<bool>(traversal[traversal_ind / 8] & (1 << (traversal_ind % 8)));
            if (!current_direction)
            {
                v->right = new tree_node();
                construction_dfs(v->right, traversal, len, ++traversal_ind, symbols, symbols_ind);
            }
        }
    }
    else if (v->left == nullptr)
    {
        v->value = symbols[symbols_ind++];
    }
}

void tree::traversal_dfs(tree_node* v, std::vector<symbol>& traversal, uint16_t& ind, std::vector<symbol>& symbols)
{
    if (v == nullptr)
    {
        return;
    }

    if (v->value != NONE)
    {
        symbols.push_back(v->value);
        return;
    }

    go_left(traversal, ind);
    traversal_dfs(v->left, traversal, ind, symbols);
    go_right(traversal, ind);
    traversal_dfs(v->right, traversal, ind, symbols);
}

void tree::go_left(std::vector<symbol>& traversal, uint16_t& ind)
{
    if (ind == traversal.size() * 8)
    {
        traversal.push_back(0);
    }

    uint16_t outer_ind = ind / (sizeof(char) * 8);
    uint16_t inner_ind = ind % (sizeof(char) * 8);

    traversal[outer_ind] |= (1 << inner_ind);
    ++ind;
}

void tree::go_right(std::vector<symbol>& traversal, uint16_t& ind)
{
    if (ind == traversal.size() * 8)
    {
        traversal.push_back(0);
    }

    uint16_t outer_ind = ind / (sizeof(char) * 8);
    uint16_t inner_ind = ind % (sizeof(char) * 8);

    traversal[outer_ind] &= ~(1 << inner_ind);
    ++ind;
}

void tree::invalid_tree() const
{
    throw std::runtime_error("Runtime error: huffman tree data corrupted");
}