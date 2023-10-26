// includes
#include <cs50.h>
#include <stdio.h>

// declare function prototype
int add_sides(int a, int b, int c);
bool valid_triangle(float x, float y, float z);

int main(void)
{
    // ask user for input
    int x = get_int("Side 1: ");
    int y = get_int("Side 2: ");
    int z = get_int("Side 3: ");

    // add the two numbers together via a function call

    if (valid_triangle (x, y, z))
    {
        int triangle = add_sides(x, y, z);

        // output the result
        printf("The sum of %i, %i and %i is %i!\n", x, y, z, triangle);
    }
    else
    {
    printf("The numbers are false\n");
    return 1;
    }

}

int add_sides(int a, int b, int c)
{
    int sum = a + b + c;
    return sum;
}

bool valid_triangle(float x, float y, float z)
{
    // check for all positive sides
    if (x <= 0 || y <=0 || z <= 0)
    {
        return false;
    }
    // check that sum of any two sides greater than third
    if ((x + y <= z) || (x + z <= y) || (y + z <= z))
    {
        return false;
    }
    // if we passed both tests, we're good!
    return true;
}

