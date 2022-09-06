#include <iostream>
#include <algorithm>

#include "vector.h"
#include "list.h"
int main()
{
	my_data_structure::vector<int> v{ 1,2,3,4,5 };
    std::cout << "vector: ";
    for (auto i : v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
}