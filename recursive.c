#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    int height = get_int("Height: ");
    draw(height);
    //draw(1); infinite loop, will crash!
}


void draw(int n)
{
    //make sure it does not loop forever
    if (n <= 0)
    {
        return;
    }

    draw(n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
    // Eternal Loop
    // for (int i = 0; i < n; i++)
    // {
    //    printf("#");
    // }
    // printf("\n");
    // draw(n + 1);
}