#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
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

int main(int argc, char *argv[])
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    sort(v.begin(), v.end());
    for (auto i: v)
        cout << i << " ";
}
