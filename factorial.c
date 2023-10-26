#include <cs50.h>
#include <stdio.h>

int factorial(int number);

int main(void)
{
    // Promt the user for a number
    int n = get_int("Enter number: ");
    printf("%i\n", factorial(n));

}

int factorial(int number)
{
    // base case
    if (number == 1)
    {
        return 1;
    }

    // recursive case
    return number * factorial(number - 1);
}

