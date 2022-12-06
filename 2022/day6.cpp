#include <vector>
#include <algorithm>
#include <fstream>
#include <string>


int main()
{
    std::ifstream from_file("data/day6.input");
    std::string str, sub;
    std::getline(from_file, str);
    int len1 = 4, len2 = 14, ind = 0, unique_chars_cnt;
    do
    {
        sub = str.substr(ind++, len2);
        std::sort(sub.begin(), sub.end());
        unique_chars_cnt = unique(sub.begin(), sub.end()) - sub.begin();
    }
    while (unique_chars_cnt != len2);
    
    printf("%d\n", ind + len2 - 1); // part 2 answer
    return 0;
}

