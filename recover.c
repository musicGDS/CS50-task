#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }

    // Open file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Usage: ./recover image");
        return 1;
    }

    // declare buffer
    BYTE *buffer = malloc(512 * sizeof(BYTE));

    // declare file name
    char filename[8];

    FILE *img = NULL;

    // image count
    int count = 0;

    while (true)
    {
        // fill buffer
        int size = fread(buffer, sizeof(BYTE), 512, file);

        // check if it is an end of file
        if (size == 0)
        {
            break;
        }

        // close file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0 && img != NULL)
        {
            fclose(img);
            count++;
        }

        // start file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg", count);
            img = fopen(filename, "w");
        }

        // continue filling file
        if (img != NULL)
        {
            fwrite(buffer, sizeof(BYTE), size, img);
        }
    }
    fclose(img);
    fclose(file);
    free(buffer);
    return 0;
}
