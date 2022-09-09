#include <iostream>
#include <algorithm>

#include "Matrix.h"
#include "vector.h"
#include "list.h"

using namespace std;

int main() {
    try {
        List<int> list{1, 2, 3, 4, 5};
        cout << list << endl<<endl;
        list.erase(2);
        cout << static_cast<string>(list) << endl;
        cout << endl << "?" << list.index_of(2);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}