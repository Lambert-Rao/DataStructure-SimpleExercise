//
// Created by Limpol on 2022/9/12.
//

#pragma once
#include <algorithm>
#include "list.h"

class arrayQueue {
public:
    arrayQueue(int initial_capacity = 10) : capacity(initial_capacity), _front(0), _rear(0) {
        queue = new int[capacity];
    }

    ~arrayQueue() { delete[] queue; }

    bool empty() const { return _front == _rear; }

    int size() const { return (_rear - _front + capacity) % capacity; }

    int &front() const { return queue[_front]; }

    int &rear() const { return queue[_rear]; }

    void pop() { _front = (_front + 1) % capacity; }

    void push(const int &data) {
        if (size() == capacity - 1) {
            changeSize();
        }
        _rear = (_rear + 1) % capacity;
        queue[_rear] = data;
    }
private:
int *queue;
    int capacity;
    int _front;
    int _rear;

    void changeSize() {
        using namespace std;
        int *new_queue = new int[capacity * 2+1];
        int start = (_front + 1) % capacity;
        if (start < 2) {
            copy(queue + start, queue + start + capacity - 1, new_queue);
        } else {
            copy(queue + start, queue + capacity, new_queue);
            copy(queue, queue + _rear + 1, new_queue + capacity - start);
        }
        _front = capacity * 2 - 1;
        _rear = capacity - 2;
        capacity = capacity*2+1;
        delete[] queue;
        queue = new_queue;
    }
};

template<typename T>
class linkedQueue {
public:
    linkedQueue() = default;

    ~linkedQueue() { clear(); }

    bool empty() const { return _front == nullptr; }

    int size() const { return _size; }

    T &front() const { return _front->element; }

    T &rear() const { return _rear->element; }

    void pop() {
        auto old = _front;
        _front = _front->next;
        delete old;
        _size--;
    }

    void push(const T &data) {
        auto newNode = new ListNode<T>(data);
        if (_rear == nullptr) {
            _front = newNode;
        } else {
            _rear->next = newNode;
        }
        _rear = newNode;
        _size++;
    }

    void clear() {
        while (!empty()) {
            pop();
        }
    }
private:
    ListNode<T> *_front = nullptr;
    ListNode<T> *_rear = nullptr;
    int _size = 0;
};