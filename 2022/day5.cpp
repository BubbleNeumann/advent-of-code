#include <vector>
#include <fstream>
#include <string>
#include <regex>

int main()
{
    std::ifstream from_file("data/day5.input");
    std::string str;
    std::getline(from_file, str);
    std::vector<std::string> vec1(str.length()/4 + 1, ""), vec2(vec1.size(), "");
    do
    {
        for(int i = 1; i < str.length(); i += 4)
        {
            if(str[i] == ' ') continue;
            vec1[i/4] += str[i];
            vec2[i/4] += str[i];
        }
    }
    while(std::getline(from_file, str) && str[0] == '['); // get crates stacks

    std::getline(from_file, str); // skip empty line
    while(std::getline(from_file, str)) // get movements
    {
        std::smatch sm;
        std::string::const_iterator search_start(str.cbegin());
        int ind[3];
        for(int i = 0; i < 3; ++i)
        {
            std::regex_search(search_start, str.cend(), sm, std::regex("([0-9])+"));
            search_start = sm.suffix().first;
            ind[i] = stoi(sm[0]);
        }
        
        vec2[ind[2]-1] = vec2[ind[1]-1].substr(0, ind[0])+ vec2[ind[2]-1];
        str = vec1[ind[1]-1].substr(0, ind[0]);
        reverse(str.begin(), str.end());
        vec1[ind[2]-1] = str + vec1[ind[2]-1];
        vec2[ind[1]-1].erase(0, ind[0]);
        vec1[ind[1]-1].erase(0, ind[0]);
    }

    for (auto elem : vec1) printf("%s\n", elem.c_str());
    printf("\n");
    for (auto elem : vec2) printf("%s\n", elem.c_str());
    
    from_file.close();
    return 0;
}
