#include "CubeGame/DotProduct.hpp"

#include <fmt/format.h>

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

std::vector<int> readFile(const std::string fileName){
    std::ifstream iFile(fileName);
    if(!iFile){
        throw std::invalid_argument(fmt::format("Unable to open file \"{}\"", fileName));
    }

    std::string line;
    std::vector<int> out;

    while(std::getline(iFile, line)){
        out.push_back(std::stoi(line));
    }

    return out;
}

std::string usage = 
R"(./CubeGame file1 file2
Where file1 and fil2 are text files with one vector entry per line. See examples in data/)";

int main(int argc, char* argv[]){
    if(argc != 3){
        std::cerr << "Requires two arguments, usage:\n";
        std::cerr << usage;
        return 1;
    }

    std::vector<int> a = readFile(argv[1]);
    std::vector<int> b = readFile(argv[2]);

    fmt::print("[{}] DOT ", fmt::join(a, ", "));
    fmt::print("[{}] = ",   fmt::join(b, ", "));
    fmt::print("{}\n", CubeGame::DotProduct(a, b));

    return 0;
}
