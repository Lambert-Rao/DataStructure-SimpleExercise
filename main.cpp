#include <iostream>
#include <algorithm>

#include "Matrix.h"
#include "Vector.h"
#include "list.h"
#include "stack.h"
#include "stack_application.h"
#include "queue_application.h"
#include "queue.h"
#include "sorted_chain.h"
#include "skip_list.h"

using namespace std;

int main()
{
    skipList<int, string> s1(1555555, 1024312);
    s1.insert(pair<int, string>(1, "one"));
    s1.insert(pair<int, string>(2, "two"));
    for(int i = 0; i < 100; i++)
    {
        s1.insert(pair<int, string>(i, "i"));
    }
    s1.show();
}