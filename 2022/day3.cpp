#include <fstream>
#include <string>

int part1()
{
    std::ifstream from_file("data/day3.input");
    std::string str;
    int ans = 0;
    
    while(std::getline(from_file, str))
    {
        for (auto ch : str.substr(0, str.length()/ 2))
        {
            if (str.substr(str.length() / 2 ).find(ch) != -1)
            {
                ans += (ch - 'Z' > 0) * (ch - 'a') + (ch - 'Z' <= 0) * (ch - 'A' + 26) + 1;
                break;
            }
        }
    }

    from_file.close();
    return ans;
}

int part2()
{
    std::ifstream from_file("data/day3.input");
    // std::string first, second, third;
    int ans1 = 0, ans2 = 0;
    std::string group[3];
    while(std::getline(from_file, group[0]))
    {
        std::getline(from_file, group[1]);
        std::getline(from_file, group[2]);
        for (auto ch : group[0])
        {
            
            if (group[1].find(ch) != -1 && group[2].find(ch) != -1)
            {
                ans2 += (ch - 'Z' > 0) * (ch - 'a') + (ch - 'Z' <= 0) * (ch - 'A' + 26) + 1;
                break;               
            }
        }
    }

    from_file.close();
    return ans2;
}

int main()
{

    printf("%d %d\n", part1(), part2());
    return 0;
}

