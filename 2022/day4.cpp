#include <fstream>
#include <string>

int main()
{
    std::ifstream from_file("data/day4.input");
    std::string str;
    int ans1 = 0, ans2 = 0;
    int sect[4];
    while(std::getline(from_file, str))
    {
        sect[0] = stoi(str.substr(0, str.find('-')));
        sect[1] = stoi(str.substr(str.find('-')+1, str.find(',')-str.find('-')-1));
        sect[2] = stoi(str.substr(str.find(',')+1, str.find('-', str.find(','))-str.find(',')-1));
        sect[3] = stoi(str.substr(str.find('-', str.find(','))+1));

        ans1 += ((sect[0] <= sect[2] && sect[3] <= sect[1]) || (sect[2] <= sect[0] && sect[1] <= sect[3]));
        ans2 += ((sect[1] >= sect[2] && sect[3] >= sect[1]) || (sect[3] >= sect[0] && sect[3] <= sect[1]));
    }
    
    printf("%d %d\n", ans1, ans2);
    from_file.close();
    return 0;
}

