//
// Created by Limpol on 2022/10/10.
//

#pragma once

#include <memory>

template<typename T>
class TreeNode
{

public:
    T element;
    using ptr = std::unique_ptr<TreeNode<T>>;
    ptr left = nullptr;
    ptr right = nullptr;
    inline int height() const
    {
        int leftHeight = left ? left->height() : 0;
        int rightHeight = right ? right->height() : 0;
        return 1 + std::max(leftHeight, rightHeight);
    }
    TreeNode() = default;

    explicit TreeNode(T data) : element(data), left(nullptr), right(nullptr)
    {}

private:
    TreeNode(T data, ptr left, ptr right) :
            element(data), left(left), right(right)
    {}

};

template<typename T>
class AVL_Tree
{
public:
    using ptr = std::unique_ptr<TreeNode<T>>;

    AVL_Tree() : root(nullptr)
    {}

    explicit AVL_Tree(T data) : root(new TreeNode<T>(data))
    {}

    AVL_Tree(T data, AVL_Tree<T> &left, AVL_Tree<T> &right) :
            root(new TreeNode<T>(data, left.root, right.root, nullptr))
    {
        left.root = nullptr;
        right.root = nullptr;
    }

    ~AVL_Tree() = default;

    ptr search(const T &);

    void insert(T data)
    {
        insert(data, root);
    }

    void remove(T data)
    {
        remove(data, root);
    }

    bool empty()
    { return root == nullptr; }

    void clear()
    { destroy(root); }

    void print()
    { print(root); }

private:
    ptr root;

    ptr RR_rotate(ptr &);
    ptr LL_rotate(ptr &);
    ptr LR_rotate(ptr &);
    ptr RL_rotate(ptr &);
};

template<typename T>
std::unique_ptr<TreeNode<T>> AVL_Tree<T>::search(const T &x)
{
    auto t = root;
    auto p(t);
    while (t != nullptr)
    {
        p = t;
        if (t->element == x)
            return t;
        else if (t->element > x)
            t = t->left;
        else
            t = t->right;
    }
    return p;
}

template<typename T>
typename AVL_Tree<T>::ptr AVL_Tree<T>::RR_rotate(AVL_Tree::ptr &k1)//left rotate
{
    auto k2 = k1->right;
    k1->right= k2->left;
    k2->left = k1;
    return k2;
}

template<typename T>
typename AVL_Tree<T>::ptr AVL_Tree<T>::LL_rotate(AVL_Tree::ptr &k2)
{
    auto k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    return k1;
}
