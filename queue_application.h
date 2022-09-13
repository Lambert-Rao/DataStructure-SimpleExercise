//
// Created by Limpol on 2022/9/13.
//

#pragma once
#include "queue.h"
#include<iostream>
namespace queue_application_arrangetrains
{
    using queue = linkedQueue<int>;
    queue first_station, target_station,buf[9];
    void arrangeTrains()
    {
        target_station.push(2);
        first_station.push(4);
        first_station.push(6);
        first_station.push(5);
        first_station.push(3);
        first_station.push(1);
        first_station.push(7);
        first_station.push(8);
        first_station.push(9);

        while (!first_station.empty())
        {
            auto train = first_station.pop();
            if(train==target_station.rear()+1)
            {
                target_station.push(train);
                continue;
            }
            else
            {
                for (int i = 0; i < 9; ++i)
                {
                    if(buf[i].empty())
                    {
                        buf[i].push(train);
                        break;
                    }
                    else if(buf[i].rear()<train)
                    {
                        buf[i].push(train);
                        break;
                    }
                }
            }
        }
        while(target_station.size()!=11)
        {
           for(int i=0;!buf[i].empty();++i)
           {
               if(buf[i].rear()==target_station.rear()+1)
               {
                   target_station.push(buf[i].pop());
                   break;
               }
           }
        }
    }

    void Test()
    {
        arrangeTrains();
        for(int i=0;i<10;++i)
        {
            std::cout<<target_station.front()<<std::endl;
        }
    }
}
//unfinished

