//
// Created by Limpol on 2022/9/13.
//

#pragma once

#include "queue.h"
#include<iostream>

namespace queue_application_arrangetrains {
    using queue = linkedQueue<int>;
    queue first_station, target_station, buf[9];

    void show() {
        std::cout << "first_station: ";
        first_station.output();
        std::cout << std::endl;
        for (int i = 0; !buf[i].empty(); i++) {
            std::cout << "buf[" << i << "]: ";
            buf[i].output();
            std::cout << std::endl;
        }
        std::cout << "target_station: ";
        target_station.output();
        std::cout << std::endl;

    }

    void arrangeTrains() {
        target_station.push(0);
        first_station.push(2);
        first_station.push(4);
        first_station.push(6);
        first_station.push(5);
        first_station.push(3);
        first_station.push(1);
        first_station.push(7);
        first_station.push(8);
        first_station.push(9);

        while (!first_station.empty()) {
            auto train = first_station.pop();
            if (train == target_station.rear() + 1) {
                target_station.push(train);
                show();
                continue;
            } else {
                for (int i = 0; i < 9; ++i) {
                    if (buf[i].empty()) {
                        buf[i].push(train);
                        show();
                        break;
                    } else if (buf[i].rear() < train) {
                        buf[i].push(train);
                        show();
                        break;
                    }
                }
            }
        }
        while (target_station.size() != 10) {
            for (int i = 0; i != 9 && !buf[i].empty(); ++i) {

                if (buf[i].front() == target_station.rear() + 1) {
                    target_station.push(buf[i].pop());
                    show();

                }

            }
        }

    }

    void Test() {
        arrangeTrains();
    }

}

namespace queue_application_maze {
    const array<char, 10> flag{' ', '*'};
    using point = std::pair<int, int>;
    linkedQueue <vector<point>> circle;
    vector<vector<int>> maze = {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
            {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
            {1, 0, 1, 0, 0, 0, 1, 1, 0, 1},
            {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
            {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    void find_path(point x, point y) {
        maze[x.first][x.second] = 100;
        int cnt = 100;

        do {
            ++cnt;
            for (auto i = circle.rear().begin(); i != circle.rear().end(); ++i) {
                if (i->first == y.first && i->second == y.second) {
                    std::cout << "find path" << std::endl;
                    break;
                } else {
                    if (maze[i->first + 1][i->second + 1] == 0) {
                        maze[i->first + 1][i->second + 1] = cnt;
                    } else if (maze[i->first - 1][i->second + 1] == 0) {
                        maze[i->first - 1][i->second + 1] = cnt;
                    } else if (maze[i->first + 1][i->second - 1] == 0) {
                        maze[i->first + 1][i->second - 1] = cnt;
                    } else if (maze[i->first - 1][i->second - 1] == 0) {
                        maze[i->first - 1][i->second - 1] = cnt;
                    }
                }
            }
        } while (1);
    }

    void show(vector<vector<int>> m = maze) {
        for (auto i = m.cbegin(); i != m.cend(); i++) {
            for (auto j = i->cbegin(); j != i->cend(); j++) {
                std::cout << *j << ' ';
            }
            std::cout << std::endl;
        }
    }
    void Test()
    {
        point x{1, 1}, y{8, 8};
        find_path(x, y);
        show();
    }
}
//: unfinished