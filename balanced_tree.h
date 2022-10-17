//
// Created by Limpol on 2022/10/10.
//

#pragma once

#include <memory>
#include <sstream>

template<typename T>
class TreeNode
{

public:
    T element;
    using ptr = std::unique_ptr<TreeNode<T>>;
    ptr left = nullptr;
    ptr right = nullptr;

    [[nodiscard]] inline int height() const
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

    void insert(T data){insert(data, root);}
    void remove(T data){remove(data,root);}

    bool empty()
    { return root == nullptr; }

    void clear()
    { destroy(root); }


private:
    ptr root;

    ptr RR_rotate(ptr &);

    ptr LL_rotate(ptr &);

    ptr LR_rotate(ptr &);

    ptr RL_rotate(ptr &);

    ptr insert(T data, ptr target);
    ptr remove(T data, ptr target);
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
    k1->right = k2->left;
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

template<typename T>
typename AVL_Tree<T>::ptr AVL_Tree<T>::LR_rotate(AVL_Tree::ptr &k3)
{
    k3->left = RR_rotate(k3->left);
    return LL_rotate(k3);
}

template<typename T>
typename AVL_Tree<T>::ptr AVL_Tree<T>::RL_rotate(AVL_Tree::ptr &k1)
{
    k1->right = LL_rotate(k1->right);
    return RR_rotate(k1);
}

template<typename T>
typename AVL_Tree<T>::ptr AVL_Tree<T>::insert(T data,ptr target)
{
    if (target == nullptr)
    {
        target = std::make_unique<TreeNode<T>>(data);
        return target;
    }
    else if (data < target->element)
    {
        target->left = insert(data, target->left);
        if (target->left->height() - target->right->height() == 2)
        {
            if (data < target->left->element)
                target = LL_rotate(target);
            else
                target = LR_rotate(target);
        }
    }
    else if (data > target->element)
    {
        target->right = insert(data, target->right);
        if (target->right->height() - target->left->height() == 2)
        {
            if (data > target->right->element)
                target = RR_rotate(target);
            else
                target = RL_rotate(target);
        }
    }
    return target;
}

template<typename T>
typename AVL_Tree<T>::ptr AVL_Tree<T>::remove(T data, AVL_Tree::ptr target)
{
    if(target == nullptr)
        return nullptr;
    if(data < target->element)
    {
        target->left = remove(data,target->left);
        if(target->right->height() - target->left->height() == 2)
        {
            if(target->right->left->height() > target->right->right->height())
                target = RL_rotate(target);
            else
                target = RR_rotate(target);
        }
    }
    else if(data > target->element)
    {
        target->right = remove(data,target->right);
        if(target->left->height() - target->right->height() == 2)
        {
            if(target->left->right->height() > target->left->left->height())
                target = LR_rotate(target);
            else
                target = LL_rotate(target);
        }
    }
    else
    {
        if(target->left && target->right)
        {
            if(target->left->height() > target->right->height())
            {
                auto max = target->left;
                while(max->right)
                    max = max->right;
                target->element = max->element;
                target->left = remove(max->element,target->left);
            }
            else
            {
                auto min = target->right;
                while(min->left)
                    min = min->left;
                target->element = min->element;
                target->right = remove(min->element,target->right);
            }
        }
        else
        {
            target = target->left ? target->left : target->right;
        }
    }
}
