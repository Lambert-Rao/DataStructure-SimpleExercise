#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>

#include "Matrix.h"
#include "Vector.h"
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

using namespace std;

int main(int argc,char *argv[])
{
    max_HBLT<int> tree{1,2,3,4,5,6,7,8,9,10};
    tree.push(4);
    tree.push(4);
    tree.pop();
    cout<<tree.Size();

}