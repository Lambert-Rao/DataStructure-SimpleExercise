#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>


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

using namespace std;

int main(int argc,char *argv[])
{
    priority_queue<int,vector<int>> pq;
    pq.push(80);
    pq.push(2);
    cout<<pq.top()<<endl;


}