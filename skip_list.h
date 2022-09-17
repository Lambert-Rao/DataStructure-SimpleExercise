//
// Created by Limpol on 2022/9/15.
//

#pragma once

#include <utility>
#include <cmath>
#include <random>

template<typename key, typename value>
class skipList;

template<typename key, typename value>
class skipNode
{
    friend class skipList<key, value>;

    using ElmType = std::pair<const key, value>;
    ElmType element;
    skipNode<key, value> **next;

    skipNode(const ElmType &e, int height) : element(e)
    {
        next = new skipNode<key, value> *[height];
    }

    explicit skipNode(int height) : next(new skipNode<key, value> *[height])
    {}
};

template<typename key, typename value>
class skipList
{
    using ElmType = std::pair<key, value>;
public:
    skipList(key largekey, int maxpairs);

    const value &operator[](const key &theKey) const;

    void insert(const ElmType &thePair);
    void erase(const key &theKey);
    void show() const;

private:
    int size = 0;
    int height = 0;
    int maxheight = 0;
    key largekey;
    skipNode<key, value> **last = nullptr;//一个指针数组，指向每一层的最后一个节点，运行时动态分配

    int randomHeight();

    skipNode<key, value> *sentinal = nullptr;
    skipNode<key, value> *tail = nullptr;//结尾标志符，没有意义
    skipNode<key, value> *find(const key &k, bool mod = 0) const;//找一个节点


};

template<typename key, typename value>
skipList<key, value>::skipList(key largekey, int maxpairs):largekey(largekey)
{
    maxheight = log2(maxpairs);
    sentinal = new skipNode<key, value>(maxheight + 1);
    last = new skipNode<key, value> *[maxheight + 1];
    ElmType e;
    e.first = largekey;

    tail = new skipNode<key, value>(e, 0);
    for (auto i = 0; i <= maxheight; ++i)
    {
        sentinal->next[i]=tail;
    }
}

template<typename key, typename value>
skipNode<key, value> *skipList<key, value>::find(const key &k, bool mod) const
{
    if (k >= largekey)
        return nullptr;
    skipNode<key, value> *p = sentinal;
    for (int i = height; i >= 0; i--)
    {
        while (p->next[i]->element.first < k)
            p = p->next[i];
        if (mod)
            last[i] = p;
    }
    if (p->next[0]->element.first == k)
        return p->next[0];
    else
        return nullptr;
}

template<typename key, typename value>
int skipList<key, value>::randomHeight()
{
    static default_random_engine e(time(nullptr));
    static uniform_int_distribution<unsigned> u(0, 1);

    int lev = 0;
    while (u(e) && lev < maxheight)
        lev++;
    return lev;
}

template<typename key, typename value>
const value &skipList<key, value>::operator[](const key &theKey) const
{
    auto temp = find(theKey);
    if (temp)
        return temp->element.second;
    else
        throw out_of_range("key not found");
}

template<typename key, typename value>
void skipList<key, value>::insert(const ElmType &rhs)
{
    if (rhs.first >= largekey)
    {
        ostringstream oss;
        oss << "key too large, key = " << rhs.first << ", largekey = " << largekey;
        throw out_of_range(oss.str());
    }
    auto p = find(rhs.first, 1);
    if (p!= nullptr&&p->element.first == rhs.first)
    {
        p->element.second = rhs.second;
        return;
    } else
    {
        int lev = randomHeight();
        if (lev > height)
        {
            lev = ++height;
            last[lev] = sentinal;
        }
        p = new skipNode<key, value>(rhs, lev + 1);
        for (int i = 0; i <= lev; i++)
        {
            p->next[i] = last[i]->next[i];
            last[i]->next[i] = p;
        }
        size++;
        return;
    }
}

template<typename key, typename value>
void skipList<key, value>::erase(const key &theKey)
{
    auto p = find(theKey, 1);
    if (p == nullptr || p->element.first != theKey)
        return;
    for (int i = 0; i <= height; i++)
    {
        if (last[i]->next[i] != p)
            break;
        last[i]->next[i] = p->next[i];
    }
    delete p;
    while (height > 0 && sentinal->next[height] == tail)
        height--;
    size--;

}

template<typename key, typename value>
void skipList<key, value>::show() const
{
    cout << "size = " << size << ", height = " << height << ",largekey = "<<largekey<<endl;
    auto p= sentinal;
    while (p!=tail)
    {
        cout<<p->element.first<<"::"<<p->element.second<<"\t\t";
//        for (int i = 0;i<height ; i++)
//        {
//            cout<<p->next[i]->element.first<<"  ";
//        }
//错误，没想出解法
        cout<<endl;
        p=p->next[0];
    }


}

