//
// Created by Limpol on 2022/9/15.
//

#pragma once
#include <string>




template<typename key, typename value>
class dictionary {
public:
    virtual ~dictionary() = default;
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual value& operator[](const key &k) const = 0;
    virtual void erase(const key &k) = 0;
    virtual void insert(const key &k, const value &v) = 0;
};

class sortedChain : public dictionary<int, std::string> {
    std::string& operator[](const int &k) const override {

    }
};