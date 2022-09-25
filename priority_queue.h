//
// Created by Limpol on 2022/9/24.
//

#pragma once

#include <vector>

template<typename T>
class maxHeap
{
public:
    maxHeap() : currentSize(0)
    {}

    explicit maxHeap(int capacity) : array(capacity + 1), currentSize(0)
    {}

    explicit maxHeap(const std::initializer_list<T> &items) : array(items.size() + 10), currentSize(items.size())
    {
        array[0] = 0;
        for (auto it=items.begin();it!=items.end();++it)
            this->insert(*it);
    }

    [[nodiscard]] bool isEmpty() const
    { return currentSize == 0; }

    const T &findMax() const
    { return array[1]; }

    void insert(const T &x)
    {
        if(currentSize==array.size())
            array.resize(array.size()*2);
        int pointer = ++currentSize;
        while(pointer>1&&array[pointer/2]<x)
        {
            array[pointer]=array[pointer/2];
            pointer/=2;
        }
        array[pointer]=x;
    }

    void pop()
    {
        if (isEmpty())
            return;
        array[1] = array[currentSize--];
        percolateDown(1);
    }

    void deleteMax(T &maxItem)
    {
        if (isEmpty())
            return;
        maxItem = array[1];
        array[1] = array[currentSize--];
        percolateDown(1);
    }

    void makeEmpty()
    { currentSize = 0; }
    void print(std::ostream &out=std::cout) const
    {
        for (int i = 1; i <= currentSize; ++i)
            out << array[i] << " ";
        out << std::endl;
    }
private:
    int currentSize;
    std::vector<T> array;

    void buildHeap()
    {
        for (int i = currentSize / 2; i > 0; --i)
            percolateDown(i);
    }
    void percolateDown(int hole)
    {
        int child;
        T tmp = array[hole];

        for (; hole * 2 <= currentSize; hole = child)
        {
            child = hole * 2;
            if (child != currentSize && array[child + 1] > array[child])
                ++child;
            if (array[child] > tmp)
                array[hole] = array[child];
            else
                break;
        }
        array[hole] = tmp;
    }
};