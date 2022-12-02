#include <cstdio>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>


// https://www.youtube.com/playlist?list=PLm323Lc7iSW9oSIDihesMJXmMNfh8U59k

std::map<char, char> map{{'A', 'X'}, {'B', 'Y'}, {'C', 'Z'}};

int part1()
{
    int score = 0;
    std::ifstream from_file("data/day2.input");
    std::string str;

    while(std::getline(from_file, str))
    {
        score += 3 * (map[str[0]] == str[2]) + 6 * (((map[str[0]] - str[2] + 3) % 3) == 2) + str[2] - 'W';
        // score += 3 * (map[str[0]] == str[2]) + 6 * (str[2] - map[str[0]] == 1) + str[2] - 'W';
        // switch ((map[str[0]] - str[2] + 3) % 3)
        // {
        //     case 0: score += 3; break; // draw
        //     case 2: score += 6; break; // win
        // }
        
        // score += str[2] - 'W';
    }
    
    from_file.close();
    return score;
}

int part2()
{
    int score = 0;
    std::ifstream from_file("data/day2.input");
    std::string str;
    while (getline(from_file, str))
    {
        switch (str[2] - 'X')
        {
            case 0: score += (2 + map[str[0]] - 'X') % 3 + 1 ; break; // lose
            case 1: score += 3 + map[str[0]] - 'W'; break; // draw
            case 2: score += 6 + (1 + (map[str[0]] - 'X')) % 3 + 1; break; // win
        }

        // score += 3 * (str[2] - 'X') + 2 - (map[str[0]] - 'X') + 1;
        // printf("%d\n", score);

    }
    from_file.close();
    return score;
}

int main()
{
    printf("%d %d\n", part1(), part2());
    return 0;
}

