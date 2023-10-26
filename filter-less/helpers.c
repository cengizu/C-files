#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // take the average of the red, green, and blue values
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            // int avg = round((image[row][col].rgbtRed + image[row][col].rgbtGreen + image[row][col].rgbtBlue) / 3 );
            // image[row][col].rgbtRed = image[row][col].rgbtGreen = image[row][col].rgbtBlue = avg;
            float originalRed = image[row][col].rgbtRed;
            float originalGreen = image[row][col].rgbtGreen;
            float originalBlue = image[row][col].rgbtBlue;

            int average = round((originalRed + originalGreen + originalBlue) / 3);
            image[row][col].rgbtRed = image[row][col].rgbtGreen = image[row][col].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Use the exact algorthm in the specs
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            float originalRed = image[row][col].rgbtRed;
            float originalGreen = image[row][col].rgbtGreen;
            float originalBlue = image[row][col].rgbtBlue;

            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            // update if exceeds 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // Result
            image[row][col].rgbtRed = sepiaRed;
            image[row][col].rgbtGreen = sepiaGreen;
            image[row][col].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        // only loop through "col < width / 2"
        for (int col = 0; col < width / 2; col++)
        {
            RGBTRIPLE temp = image[row][col];
            image[row][col] = image[row][width - (col + 1)];
            image[row][width - (col + 1)] = temp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // blox blur method, image -> temp
    RGBTRIPLE temp[height][width];

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            temp[row][col] = image[row][col];
        }
    }

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int allRed, allGreen, allBlue;
            allRed = allGreen = allBlue = 0;
            float counter = 0;

            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int current_X = row + x;
                    int current_Y = col + y;

                    if (current_X < 0 || current_X > (height - 1) || current_Y < 0 || current_Y > (width - 1))
                    {
                        continue;
                    }

                    allRed += image[current_X][current_Y].rgbtRed;
                    allGreen += image[current_X][current_Y].rgbtGreen;
                    allBlue += image[current_X][current_Y].rgbtBlue;

                    counter++;
                }

                // Take average of neigbors
                temp[row][col].rgbtRed = round(allRed / counter);
                temp[row][col].rgbtGreen = round(allGreen / counter);
                temp[row][col].rgbtBlue = round(allBlue / counter);
            }
        }
    }

    // result: temp -> image

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            image[row][col].rgbtRed = temp[row][col].rgbtRed;
            image[row][col].rgbtGreen = temp[row][col].rgbtGreen;
            image[row][col].rgbtBlue = temp[row][col].rgbtBlue;
        }
    }

    return;
}
