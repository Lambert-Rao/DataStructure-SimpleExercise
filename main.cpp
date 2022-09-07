#include <iostream>
#include <algorithm>

#include "Matrix.h"
#include "vector.h"

int main()
{

    Matrix a(3,5,{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    a.print_all();
    Matrix b(a);
    (a+b).transpose().print_all();
}