#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> inp_to_vec()
{
    const char* file_name = "data/day1.input";
    std::ifstream from_file(file_name);
    std::string str;
    std::vector<std::string> inp_vec;
    while (getline(from_file, str)) inp_vec.push_back(str);
    return inp_vec;
}

int part1()
{
    return 0;
}

int part2()
{
    return 0;
} 

int main()
{
    std::vector<std::string> vec = inp_to_vec();
    for (auto i : vec) std::cout << i << "\n";
    // std::cout << part1() << " " << part2() <<"\n";
    return 0;
}
