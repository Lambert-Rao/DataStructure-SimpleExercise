//
// Created by Limpol on 2022/9/19.
//

#pragma once

#include <hash_map>
#include <string>
#include <iostream>
#include <cstring>
#include <fstream>

namespace hashing_application_LZW
{
    using namespace std;
    void set_files(int argc, char *argv[])
    {
        char output_file[100], input_file[100];
        if (argc>=3)
        {
            strcpy(input_file, argv[1]);
            strcpy(output_file, argv[2]);
        }
        else
        {
            cout << "Enter the input file name: ";
            cin >> input_file;
            cout << "Enter the output file name: ";
            cin >> output_file;
        }
        ifstream ifs(input_file, ios::in);

    }
}

