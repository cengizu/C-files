#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int number = 5;

    int guess = get_int("Whats your guess? <0-10> ");

    while (guess != number)
    {
        printf("Wrong guess!\n");
        guess = get_int("Try again! ");
    }


    printf("You're correct!\n");



}