
#include <stdio.h>

void part1(const char* fname)
{

    FILE* file = fopen(fname, "r");

    fclose(file);
}

void part2(const char* fname)
{

    FILE* file = fopen(fname, "r");

    fclose(file);
}


int main()
{
    part1("input/day2-test.txt");
    // part1("input/day2.txt");
    // part2("input/day2-test.txt");
    // part2("input/day2.txt");
    return 0;
}
