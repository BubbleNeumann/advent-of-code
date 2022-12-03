#include <fstream>
#include <string>
#include <map>

int main()
{
    int score1 = 0, score2 = 0;
    std::map<char, char> map{{'A', 'X'}, {'B', 'Y'}, {'C', 'Z'}};
    std::ifstream from_file("data/day2.input");
    std::string str;

    while(std::getline(from_file, str))
    {
        score1 += 3 * (map[str[0]] == str[2]) + 6 * (((map[str[0]] - str[2] + 3) % 3) == 2) + str[2] - 'W';
        score2 += 3 * (str[2] - 'X') + (str[2] - 'X' + 2 + (map[str[0]] - 'X')) % 3 + 1;
    }
    
    printf("%d %d\n", score1, score2);
    from_file.close();
    return 0;
}

