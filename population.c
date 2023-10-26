#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size + user must enter at least 9
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);
    // TODO: Prompt for end size + End size cannot be less than start value
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold
    int n = start;
    int years = 0;

    while (n < end)
    {
        n = n + n/3 - n/4;
        years++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}
