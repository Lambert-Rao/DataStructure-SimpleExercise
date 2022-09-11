//
// Created by Limpol on 2022/9/11.
//

#pragma once

#include "stack.h"
#include <sstream>
#include <iostream>
//p188 book
namespace stack_application_hanoi
//汉诺塔问题
{
    using Tower = VectorStack<int>;
    Tower tos[3];

    void show_status(Tower *p) {
        std::ostringstream oss;
        oss << "Tower 1: ";
        for (int i = 0; i < p[0].size(); i++) {
            oss << p[0][i] << " ";
        }
        oss << std::endl;
        oss << "Tower 2: ";
        for (int i = 0; i < p[1].size(); i++) {
            oss << p[1][i] << " ";
        }
        oss << std::endl;
        oss << "Tower 3: ";
        for (int i = 0; i < p[2].size(); i++) {
            oss << p[2][i] << " ";
        }
        oss << std::endl;
        std::cout << oss.str();
    }

    void solve(int n, int x, int y, int z)
    //把n个碟子从x移动到z
    {

        if (n > 0) {
            solve(n - 1, x, z, y);
            //把n-1个碟子从x移动到y
            tos[z].push(tos[x].pop());
            //把第n个碟子从x移动到z
            show_status(tos);
            solve(n - 1, y, x, z);
            //把n-1个碟子从y移动到z}
        }
    }

    void test(int n) {
        for (int i = n; i != 0; i--) {
            tos[0].push(i);
        }
        solve(n, 0, 1, 2);
    }

}

namespace stack_application_switchbox
//按顺序输入对应端口对
{
    auto s=new VectorStack<int>(10);
    bool check(initializer_list<int> il)
    {
        for(auto i:il)
        {
            if(s->empty())
                s->push(i);
            else if(s->top()==i)
                s->pop();
            else
                s->push(i);
        }
        return s->empty();
    }
    void test(initializer_list<int> il)
    {
        if(check(il))
            std::cout<<"Yes"<<std::endl;
        else
            std::cout<<"No"<<std::endl;
    }
}

namespace stack_application_maze
{

}