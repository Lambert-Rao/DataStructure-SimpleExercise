#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>

#include "Matrix.h"
#include "vector.h"
#include "list.h"
#include "stack.h"
#include "stack_application.h"
#include "queue_application.h"
#include "hashing_application.h"
#include "queue.h"
#include "skip_list.h"
#include "hashing.h"
#include "priority_queue.h"
#include "height_based leftist tree.h"
#include "binary_tree.h"
#include "graph.h"

using namespace std;

int main(int argc,char *argv[])
{
    adjencencyWdigraph<int> a(10);
    a.insertEdge(1,2,1);
    a.insertEdge(7,1,1);
    cout<<a.inDegree(1)<<endl<<a.outDegree(1)<<endl;

}
