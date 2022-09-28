//
// Created by Limpol on 2022/9/28.
//

#pragma once
#include <utility>
#include <memory>
#include "binary_tree.h"

template<typename T>
class max_HBLT
{
public:
    using node_type = binaryTreeNode<std::pair<uint32_t, T>>;
    max_HBLT() = default;
    max_HBLT(std::initializer_list<T> list);
    void merge(node_type &rhs);
    void push(const T &rhs);
    void pop();
    size_t Size(){return size;}
private:
    node_type *root;
    size_t size=0;

    void destroy(node_type *&root);

    void merge(node_type *&lhs, node_type *&rhs);
};

template<typename T>
void max_HBLT<T>::merge(max_HBLT::node_type *&lhs, max_HBLT::node_type *&rhs)
{
    if (!rhs)
        return;
    if (!lhs)
    {
        lhs = rhs;
        return;
    }

    if (lhs->element.second < rhs->element.second)
        std::swap(lhs, rhs);
    merge(lhs->right, rhs);
    if (!lhs->left || lhs->left->element.first < lhs->right->element.first)
        std::swap(lhs->left, lhs->right);
    lhs->element.first = lhs->right ? lhs->right->element.first + 1 : 1;

}

template<typename T>
void max_HBLT<T>::merge(max_HBLT::node_type &rhs)
{
    merge(root, rhs.root);
    size += rhs.size;
    destroy(&rhs);
}

template<typename T>
void max_HBLT<T>::destroy(max_HBLT::node_type *&root)
{
    if (root == nullptr)
        return;
    destroy(root->left);
    destroy(root->right);
    delete root;
    root = nullptr;
}

template<typename T>
void max_HBLT<T>::pop()
{
    if (root == nullptr)
        return;
    auto temp = root;
    root = nullptr;
    merge(root, temp->left);
    merge(root, temp->right);
    delete temp;
    size--;

}

template<typename T>
max_HBLT<T>::max_HBLT(std::initializer_list<T> list)
{
    std::queue<node_type *> q;
    auto s=list.size();
    for (auto &i : list)
    {
        q.push(new node_type(std::pair<uint32_t ,T>(1,i)));
    }
    while (q.size() > 1)
    {
        auto lhs = q.front();
        q.pop();
        auto rhs = q.front();
        q.pop();
        merge(lhs, rhs);
        q.push(lhs);
    }
    if(q.size())
        root = q.front();
    size = s;
}

template<typename T>
void max_HBLT<T>::push(const T &rhs)
{
    auto p = new node_type(std::pair<uint32_t ,T>(1,rhs));
    merge(root, p);
    size++;

}




