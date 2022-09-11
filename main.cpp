#include <iostream>
#include <algorithm>

#include "Matrix.h"
#include "Vector.h"
#include "list.h"
#include "stack.h"
using namespace std;

int main() {
    try {
    ListStack<int> s;
    s.push(1);
    s.push(2);
    cout<<s.top()<<endl<<s.size()<<endl;
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}