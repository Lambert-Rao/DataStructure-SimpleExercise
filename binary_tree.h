//
// Created by Limpol on 2022/9/22.
//

#pragma once
#include <iostream>
#include <queue>

template <typename T>
class binaryTree;

template <typename T>
class binaryTreeNode {
    friend class binaryTree<T>;
    T element;
    using ptr=binaryTreeNode<T> *;
    binaryTreeNode<T> *left;
    binaryTreeNode<T> *right;
    binaryTreeNode() : left(nullptr), right(nullptr) {}
    explicit binaryTreeNode(T data) : element(data), left(nullptr), right(nullptr) {}
    binaryTreeNode(T data, binaryTreeNode<T> *left, binaryTreeNode<T> *right) :
            element(data), left(left), right(right) {}
};

template <typename T>
class binaryTree {
    using ptr=binaryTreeNode<T> *;
public:
    binaryTree() : root(nullptr) {}
    explicit binaryTree(T data) : root(new binaryTreeNode<T>(data)) {}
    binaryTree(T data, binaryTree<T> &left, binaryTree<T> &right) :
            root(new binaryTreeNode<T>(data, left.root, right.root)) {
        left.root = nullptr;
        right.root = nullptr;
    }
    ~binaryTree() { clear(); }
    void clear() { clear(root); }
    void preOrder() { preOrder(root); }
    void inOrder() { inOrder(root); }
    void postOrder() { postOrder(root); }
    void levelOrder();
    int height() { return height(root); }
    int size() { return size(root); }
    bool empty() { return root == nullptr; }
    void insert(T x);
    void remove(T x);
    void remove(ptr &t, T x);
    void destroy(ptr &t);
    void copy(ptr &t, ptr other);
    void copyTree(binaryTree<T> &other);
    binaryTree<T> &operator=(binaryTree<T> &other);
    void printTree();
    void printTree(ptr t, int level);
private:
    ptr root;
    void clear(ptr &t);
    void preOrder(ptr t);
    void inOrder(ptr t);
    void postOrder(ptr t);
    int height(ptr t);
    int size(ptr t);
};

template<typename T>
void binaryTree<T>::preOrder(binaryTree::ptr t)
{
    if(t!= nullptr)
    {
        std::cout<<t->element<<std::endl;
        preOrder(t->left);
        preOrder(t->right);
    }

}

template<typename T>
void binaryTree<T>::inOrder(binaryTree::ptr t)
{
    if(t!= nullptr)
    {
        inOrder(t->left);
        std::cout<<t->element<<std::endl;
        inOrder(t->right);
    }

}

template<typename T>
void binaryTree<T>::postOrder(binaryTree::ptr t)
{
    if(t!= nullptr)
    {
        postOrder(t->left);
        postOrder(t->right);
        std::cout<<t->element<<std::endl;
    }
}

template<typename T>
void binaryTree<T>::levelOrder()
{
    auto t=root;
    std::queue<ptr> q;
    while(t!= nullptr)
    {
        std::cout<<t->element<<std::endl;
        if(t->left!= nullptr)
            q.push(t->left);
        if(t->right!= nullptr)
            q.push(t->right);
        if(!q.empty())
        {
            t=q.front();
            q.pop();
        }
        else
            t= nullptr;
    }

}

template<typename T>
int binaryTree<T>::height(binaryTree::ptr t)
{
    if(t== nullptr)
        return 0;
    else
    {
        int l=height(t->left);
        int r=height(t->right);
        return l>r?l+1:r+1;
    }
}

template<typename T>
int binaryTree<T>::size(binaryTree::ptr t)
{
    if(t== nullptr)
        return 0;
    else
        return size(t->left)+size(t->right)+1;
}

