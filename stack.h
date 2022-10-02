//
// Created by Limpol on 2022/9/10.
//

#pragma once

#include "vector.h"
#include "list.h"

template<typename T>
class Stack {
public:
    virtual ~Stack() = default;
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual T& top() const = 0;
    virtual T pop() = 0;
    virtual void push(const T &data) = 0;
};

template<typename T>
class VectorStack : public Stack<T> , public vector<T> {
public:
    VectorStack(int initial_capacity = 10) : vector<T>(initial_capacity) {}
    bool empty() const override { return vector<T>::empty(); }
    int size() const override { return vector<T>::size(); }
    T& top() const override { return vector<T>::_pointer[size() - 1]; }
    T pop() override { return vector<T>::pop_back(); }
    void push(const T &data) override { vector<T>::push_back(data); }
};

template<typename T>
class ListStack : public Stack<T> , public List<T> {
    friend class ListNode<T>;
public:
    ListStack() = default;
    bool empty() const override { return List<T>::empty(); }
    int size() const override { return List<T>::size; }
    T& top() const override { return List<T>::last(); }
    void push(const T &data) override { List<T>::push_back(data); }
};