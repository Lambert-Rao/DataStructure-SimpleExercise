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

using namespace std;

int main(int argc,char *argv[])
{
    priority_queue<int> a{};
    for (int i = 0; i < 10; ++i)
    {
        a.push(i);
    }
    for (int i = 0; i < 10; ++i)
    {
        cout << a.top() << endl;
        a.pop();
    }
    return 0;


}