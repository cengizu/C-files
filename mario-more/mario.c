#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //define all ints
    int height, line, column, space;

    // Height must be between 1 - 8
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Create new line until height
    for (line = 0; line < height; line++)
    {
        // Add spaces before for each # until height-1. (Space = height - Line - 1)
        for (space = 0; space < height - line - 1; space++)
            {
                printf(" ");
            }

        // LEFT SIDE: Generate increasing amount of hashtags # per each line
        for (column = 0; column <= line; column++)
            {
                printf("#");
            }

        // Divider between pyramid's both sides
        printf("  ");

        // RIGHT SIDE: Generate increasing amount of hashtags # per each line
        for (column = 0; column <= line; column++)
            {
                printf("#");
            }
        // New line
        printf("\n");
    }
}