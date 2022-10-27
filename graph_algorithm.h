//
// Created by Limpol on 2022/10/27.
//

#pragma once
#include "graph.h"
#include <ostream>

void testGraph()
{
    adjencencyWdigraph<int> a(10);
    a.insertEdge(1,2,1);
    a.insertEdge(7,1,1);
}