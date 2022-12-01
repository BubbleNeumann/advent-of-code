#include <fstream>
#include <string>
#include <algorithm>
#include <numeric>

const char* file_name = "data/day1.input";
std::string str;

int part1()
{
    std::ifstream from_file(file_name);
    int max_sum = 0, cur_sum = 0;
    while (getline(from_file, str))
    {
        if (str.empty()) 
        {
            max_sum = (cur_sum > max_sum) * cur_sum + (cur_sum <= max_sum) * max_sum; 
            cur_sum = 0;
            continue;
        }

        cur_sum += stoi(str);
    }

    from_file.close();
    return max_sum;
}

int part2()
{
    std::ifstream from_file(file_name);
    int sums[] = {0, 0, 0};
    int cur_sum = 0;
    while (getline(from_file, str))
    {
        if (str.empty()) 
        {
            if (cur_sum > sums[0]) sums[0] = cur_sum; // replace the smallest one
            std::sort(std::begin(sums), std::end(sums));
            cur_sum = 0;
            continue;
        }

        cur_sum += stoi(str);
    }
    
    from_file.close();
    return std::accumulate(sums, sums + 3, cur_sum);
} 

int main()
{
    printf("%d %d\n", part1(), part2());
    return 0;
}
