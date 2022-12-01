#include <fstream>
#include <string>
#include <algorithm>
#include <numeric>

int main()
{
    const char* file_name = "data/day1.input";
    std::ifstream from_file(file_name);
    std::string str;
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
    printf("%d %d\n", sums[2], std::accumulate(sums, sums + 3, cur_sum));
    return 0;
}
