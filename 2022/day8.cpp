#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::ifstream from_file("data/day8.input");
    std::vector<std::vector<int>> grid;
    std::vector<std::vector<int>> tallest_in_grid;
    std::string str;
    while(std::getline(from_file, str))
    {
        std::vector<int> tallest_in_row;
        std::vector<int> row;
        char tallest_left = '0'-1, tallest_right = '0'-1;
        for (int i = 0; i < str.length(); ++i) // go from left
        {
            row.push_back(str[i]-'0'); // add all trees into the grid
            if (str[i] > tallest_left)
            {
                tallest_left = str[i];
                tallest_in_row.push_back(i); // push back index
            }
        }
        
        for (int i = str.length() - 1; i; --i) // go from right
        {
            if (str[i] > tallest_right)
            {
                tallest_right = str[i];
                if (std::find(tallest_in_row.begin(), tallest_in_row.end(), i) == tallest_in_row.end())
                {
                    tallest_in_row.push_back(i); // push back index if it wasn't already
                }
            }
        }

        tallest_in_grid.push_back(tallest_in_row);
        grid.push_back(row);
    } 

    for (int col = 0; col < grid[col].size(); ++col)
    {
        for (int row = 0, tallest_top = -1; row < grid.size(); ++row) // go from top
        {
            if (grid[row][col] > tallest_top)
            {
                tallest_top = grid[row][col];
                if (std::find(tallest_in_grid[row].begin(), tallest_in_grid[row].end(), col) == tallest_in_grid[row].end())
                {
                    tallest_in_grid[row].push_back(col);
                }
            }
        }
        
        for (int row = grid.size()-1, tallest_bot = -1; row; --row) // go from bottom
        {
            if (grid[row][col] > tallest_bot)
            {
                tallest_bot = grid[row][col];
                if (std::find(tallest_in_grid[row].begin(), tallest_in_grid[row].end(), col) == tallest_in_grid[row].end())
                {
                    tallest_in_grid[row].push_back(col);
                }
            }
        }
    }

    int counter = 0;    
    for (auto row : tallest_in_grid)
    {
        counter += row.size();
    }

    int max_scenic_score = 0;
    for (int row = 1; row < grid.size()-1; ++row)
    {
        for (int col = 1, i; col < grid[row].size()-1; ++col)
        {
            int cur_scenic_score = 1;
            for (i = 1; row - i > 0 && grid[row][col] > grid[row-i][col]; ++i); // go up
            cur_scenic_score *= i;
            for (i = 1; row + i < grid.size()-1 && grid[row][col] > grid[row+i][col]; ++i); // go down
            cur_scenic_score *= i;
            for (i = 1; col + i < grid[row].size()-1 && grid[row][col] > grid[row][col+i]; ++i); // go right
            cur_scenic_score *= i;
            for (i = 1; col - i > 0 && grid[row][col] > grid[row][col-i]; ++i); // go left
            cur_scenic_score *= i;

            if (cur_scenic_score > max_scenic_score)
            {
                max_scenic_score = cur_scenic_score;
            }
        }
    }
        
    printf("%d\n", counter);
    printf("%d\n", max_scenic_score);
    return 0;
}
