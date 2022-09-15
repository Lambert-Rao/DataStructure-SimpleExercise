//
// Created by Limpol on 2022/9/15.
//

#pragma once

#include <utility>

template<typename key, typename value>
class skipNode
{
    using ElmType = std::pair<const key, value>;
    ElmType element;
    skipNode<key, value> **next;

    skipNode(const ElmType &e, int height) : element(e)
    {
        next = new skipNode<key, value> *[height];
    }
};