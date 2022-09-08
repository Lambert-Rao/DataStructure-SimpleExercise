#include <iostream>
#include <algorithm>

#include "Matrix.h"
#include "vector.h"

int main()
{

    SparseMatrix<int> m1(3, 3, {{{0, 0}, 1}, {{0, 1}, 2}, {{1, 1}, 3}, {{2, 2}, 4}});

    std::cout<<m1;
    SparseMatrix<int> m2 = m1.transpose();
    std::cout<<m2;
    SparseMatrix<int> m3 = m1 + m2;
    std::cout<<m3<<endl;
    cout<<m1-m2;

}