#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // int i = get_int("i: ");
    // int j = get_int("j: ");

    string s = get_string("Text 1: ");
    string t = get_string("Text 2: ");


    if (strcmp(s, t) == 0)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}