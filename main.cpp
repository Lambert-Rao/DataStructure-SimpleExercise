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

int main() {
    skipList<int, string> sl(15,102421312);
    cout<<sl.randomHeight()<<endl;
    skipList<int, string> s11(15,151255);
    cout<<s11.randomHeight()<<endl;
    skipList<int, string> s111(15,125155);
    cout<<s111.randomHeight()<<endl;

}