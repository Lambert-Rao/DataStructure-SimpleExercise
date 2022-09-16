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
    friend class skipList<key,value>;
    using ElmType = std::pair<const key, value>;
    ElmType element;
    skipNode<key, value> **next;
    skipNode(const ElmType &e, int height) : element(e)
    {
        next = new skipNode<key, value> *[height];
    }
    explicit skipNode(int height): next(new skipNode<key, value> *[height]) {}
};

template<typename key, typename value>
class skipList
{
    using ElmType = std::pair<const key, value>;
public:
    skipList(key largekey,int maxpairs);
    ElmType *find(const key &k) const;
    int randomHeight();
private:
    skipNode<key,value> *sentinal= nullptr;
    skipNode<key,value> *tail=nullptr;
    int size=0;
    int height=0;
    int maxheight=0;
    key largekey;
    skipNode<key,value> **last= nullptr;
};

template<typename key, typename value>
skipList<key, value>::skipList(key largekey, int maxpairs):largekey(largekey)
{
    maxheight=log2(maxpairs);
    sentinal=new skipNode<key,value>(maxheight+1);
    last=new skipNode<key,value>*[maxheight+1];
}

template<typename key, typename value>
std::pair<const key, value>* skipList<key, value>::find(const key &k) const
{
    if(k>=largekey)
        return nullptr;
    skipNode<key,value> *p=sentinal;
    for(int i=height;i>=0;i--)
    {
        while(p->next[i]->element.first<k)
            p=p->next[i];
    }
    if(p->next[0]->element.first==k)
        return &p->next[0]->element;
    else
        return nullptr;
}

template<typename key, typename value>
int skipList<key, value>::randomHeight()
{
    static default_random_engine e(time(nullptr));
    static uniform_int_distribution<unsigned> u(0,1);

    int lev=0;
    while (u(e) && lev<maxheight)
        lev++;
    return lev;
}

