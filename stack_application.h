//
// Created by Limpol on 2022/9/11.
//

#pragma once

#include "stack.h"
#include <sstream>
#include <iostream>
#include <bitset>
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
    auto s = new VectorStack<int>(10);

    bool check(std::initializer_list<int> il) {
        for (auto i: il) {
            if (s->empty())
                s->push(i);
            else if (s->top() == i)
                s->pop();
            else
                s->push(i);
        }
        return s->empty();
    }

    void test(std::initializer_list<int> il) {
        if (check(il))
            std::cout << "Yes" << std::endl;
        else
            std::cout << "No" << std::endl;
    }
}

namespace stack_application_maze
//一个暴力搜索迷宫“算法”
{
    template<unsigned row, unsigned col>//从零开始
    class Maze {
    public:
        Maze(std::bitset<row * col> s) : position(s) {}

        void show(std::ostream &os = std::cout) {
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    os << ((position[pos(i, j)] == 0) ? "  " : "* ");
                }
                os << std::endl;
            }
        }

        void fine_path() {
            auto past = std::bitset<row * col>(position);
            auto p = new VectorStack<unsigned>(row * col);
            p->push(pos(0, 0));
            position[pos(0, 0)] = 1;
            while (!p->empty()) {
                int i = p->top() / col;
                int j = p->top() % col;
                if (i == row - 1 && j == col - 1) {
                    for (int i = 0; i < row; i++) {
                        for (int j = 0; j < col; j++) {
                            if(past[pos(i,j)]==1)
                                std::cout<<"* ";
                            else if(position[pos(i,j)]==1 && past[pos(i,j)]==0)
                                std::cout<<"# ";
                            else
                                std::cout<<"  ";
                        }
                        std::cout << std::endl;
                    }
                    return;
                }
                if (j + 1 < col && position[pos(i, j + 1)] == 0) {
                    p->push(pos(i, j + 1));
                    position[pos(i, j + 1)] = 1;
                } else if (i + 1 < row && position[pos(i + 1, j)] == 0) {
                    p->push(pos(i + 1, j));
                    position[pos(i + 1, j)] = 1;
                } else if (j - 1 >= 0 && position[pos(i, j - 1)] == 0) {
                    p->push(pos(i, j - 1));
                    position[pos(i, j - 1)] = 1;
                } else if (i - 1 >= 0 && position[pos(i - 1, j)] == 0) {
                    p->push(pos(i - 1, j));
                    position[pos(i - 1, j)] = 1;
                } else {
                    position[p->pop()] = 1;
                }
            }
            std::cout << "No path" << std::endl;
        }

    private:
        std::bitset<row * col> position;

        inline unsigned pos(unsigned x, unsigned y) {
            return x * col + y;
        }
    };

    void test() {
        Maze<10, 10> m(static_cast<std::bitset<100>>(
                "0111111000111110001010000101000"
                "01111100010100001010010100101000"
                "0111100010101010101001010101010"
                       ));
        std::cout<<"initial:"<<std::endl;
        m.show();
        std::cout<<"result:"<<std::endl;
        m.fine_path();
    }
}