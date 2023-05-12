#include "Utilities.h"
#include <fstream>
#include <iostream>

namespace util {
    std::vector<std::vector<std::string>> read_delim_file(std::string file_path, char delim) {
    std::ifstream file(file_path);

    if(not file.is_open()) {
        std::cerr << "ERROR: " << file_path << " cannot be opened.\n";
        exit(-1);
    }

    std::string line;
    std::vector<std::vector<std::string>> data;

    while(getline(file, line)) {
        std::vector<std::string> tmp;

        std::string::size_type start = 0;
        std::string::size_type offset = line.find_first_of(delim, start);

        while(offset != std::string::npos) {
            tmp.push_back(line.substr(start, offset - start));
            start = offset + 1;
            offset = line.find_first_of(delim, start);
        }

        tmp.push_back(line.substr(start, offset - start));
        data.push_back(tmp);
    }

    return data;
    }
}
