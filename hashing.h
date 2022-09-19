////
//// Created by Limpol on 2022/9/17.
//

#pragma once

#include <string>
#include "list.h"
#include <array>
#include <utility>

template<uint64_t N = 100>
class hashTable
{
    using hashlist=List<std::pair<std::string,std::string>>;
public:
    hashTable() = default;

    void insert(std::pair<string, string> rhs);
    hashTable& operator=(const hashTable &rhs)= default;
    string operator[](const string &rhs);

    size_t size;
private:
    uint64_t find(const string &key);

    static uint64_t string_to_int(std::string s);

    std::array<hashlist , N> table;
};


template<uint64_t N>
uint64_t hashTable<N>::string_to_int(std::string s)
{
    uint64_t hashvalue = 0;
    uint32_t len = s.length();
    for (uint32_t i = 0; i < len; i++)
    {
        hashvalue = hashvalue * 5 + s.at(i);
    }
    return hashvalue;
}

template<uint64_t N>
uint64_t hashTable<N>::find(const string &key)
{
    auto n = string_to_int(key) % N;

    if (table[n].first().element.first == key)
    {
        return n;
    }
    else
    {
        return -1;
    }
}

template<uint64_t N>
string hashTable<N>::operator[](const string &rhs)
{
    auto n = find(rhs);
    if (n != -1)
    {
        ostringstream oss;
        auto p = table[n].begin();
        for(;p!=table[n].end();p=p->next)
        {
            if(p->element.first==rhs)
            {
                oss<< p->element.second<<" ";
            }
        }
        return oss.str();
    } else
        throw std::out_of_range("key not found");
}

template<uint64_t N>
void hashTable<N>::insert(std::pair<string, string> rhs)
{
    auto n = find(rhs.first);
    table[n].push_back(rhs);
}
//额啊啊啊啊啊啊啊！
//到底有什么问题啊！

/*class Hash
{
    int BUCKET;    // No. of buckets

    // Pointer to an array containing buckets
    list<int> *table;
public:
    Hash(int V);  // Constructor

    // inserts a key into hash table
    void insertItem(int x);

    // deletes a key from hash table
    void deleteItem(int key);

    // hash function to map values to key
    int hashFunction(int x)
    {
        return (x % BUCKET);
    }

    void displayHash();
};

Hash::Hash(int b)
{
    this->BUCKET = b;
    table = new list<int>[BUCKET];
}

void Hash::insertItem(int key)
{
    int index = hashFunction(key);
    table[index].push_back(key);
}

void Hash::deleteItem(int key)
{
    // get the hash index of key
    int index = hashFunction(key);

    // find the key in (index)th list
    list<int>::iterator i;
    for (i = table[index].begin();
         i != table[index].end(); i++)
    {
        if (*i == key)
            break;
    }

    // if key is found in hash table, remove it
    if (i != table[index].end())
        table[index].erase(i);
}

// function to display hash table
void Hash::displayHash()
{
    for (int i = 0; i < BUCKET; i++)
    {
        cout << i;
        for (auto x: table[i])
            cout << " --> " << x;
        cout << endl;
    }
}*/

