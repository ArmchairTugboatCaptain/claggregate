#ifndef UTILITIES_H
#define UTILITIES_H

#include <vector>
#include <string>

namespace util{
    std::vector<std::vector<std::string>> read_delim_file(std::string file_path, char delim);
}

#endif