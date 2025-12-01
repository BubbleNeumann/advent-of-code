
#include <limits.h> // abs
#include <stdio.h>
#include <stdlib.h>

const int INIT_DIAL_PTR = 50;

void part1(const char* filename) // solved
{
    FILE* file = fopen(filename, "r");
    int dial_ptr = INIT_DIAL_PTR;
    int dir /* rotation direction */, r /* rotate by */, cnt /* antwort */;
    int c;

    while ((c = fgetc(file)) != EOF)
    {
        dir = c == 'L' ? 0 : 1; // L or R
        r = 0;
        while ((c=fgetc(file)) - 13) r = r * 10 + c - '0';
        dial_ptr += dir ? r : -r;
        cnt += dial_ptr % 100 == 0;
        fgetc(file); // read newline
    }
    fclose(file);
    printf("(1) done=%d\n", cnt);
}

void part2(const char* filename)
{
    FILE* file = fopen(filename, "r");
    int dial_ptr = INIT_DIAL_PTR;
    int dir /* rotation direction */, r /* rotate by */, cnt /* antwort */;
    int c;

    while ((c = fgetc(file)) != EOF)
    {
        dir = c == 'L' ? 0 : 1; // L or R
        r = 0;
        while ((c=fgetc(file)) - 13) r = r * 10 + c - '0';
        int prev_dial_ptr = dial_ptr;
        dial_ptr += dir ? r : -r;

        int diff = dial_ptr - prev_dial_ptr;

        // correction
        // dial_ptr += 100 * (dial_ptr < 0) - 100 * (dial_ptr > 200);

        cnt += ((dial_ptr % 100) == 0) || diff / 100 == 1 || dial_ptr * prev_dial_ptr < 0;

        fgetc(file); // read newline
    }
    fclose(file);
    printf("(2) done=%d\n", cnt);
}

int main()
{
    // part1("input/day1-test.txt");
    // part1("input/day1.txt");
    part2("input/day1-test.txt");
    // part2("input/day1.txt");
    return 0;
}
