#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // check if argv is entered
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // check the file is valid
    FILE *input_file = fopen(argv[1], "r");

    if (input_file == NULL)
    {
        printf("Couldn't open file");
        return 2;
    }

    // Declare variables and files
    unsigned char buffer[512];
    int num_images = 0;

    FILE *output_file = NULL;

    char *filename = malloc(8 * sizeof(char));

    // Check first 512 bytes of memory if it is Jpeg

    while (fread(buffer, sizeof(char), 512, input_file))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Prevent memory leakage
            if (num_images > 0)
            {
                fclose(output_file);
            }

            // Write the filenames
            sprintf(filename, "%03i.jpg", num_images);

            output_file = fopen(filename, "w");

            num_images++;
        }

        // write the file
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }

    // Free memory and close files
    free(filename);
    fclose(output_file);
    fclose(input_file);

    return 0;
}