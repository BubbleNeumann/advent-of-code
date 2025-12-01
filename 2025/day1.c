
#include <stdio.h>
// #include <stdlib.h>


void part1(const char* filename)
{
    FILE* file = fopen(filename, "r");

    // char* input;

    int dial_ptr = 50;

    int c;

    while ((c = fgetc(file)) != EOF)
    {

        putchar(c);
    }


    fclose(file);
    printf("done\n");
}


void part2()
{

}

int main()
{
    part1("input/day1-test.txt");
    return 0;
}
