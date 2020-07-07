#include "helpers.h"
#include <math.h>
#include <stdlib.h>


float calculateSobel(float x, float y);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // Getting average
            int new_value = roundf(( (float) image[h][w].rgbtBlue + (float) image[h][w].rgbtGreen + (float) image[h][w].rgbtRed) / 3);
            // replacing by the same value
            image[h][w].rgbtBlue = new_value;
            image[h][w].rgbtGreen = new_value;
            image[h][w].rgbtRed = new_value;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Creating temporary valu to reflect ?can it be with malloc?
    RGBTRIPLE new_image[height][width];

    // drawing image backwards to new_image
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            new_image[h][width - 1 - w] = image[h][w];
        }
    }
    // puting the result back to image
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            image[h][w] = new_image[h][w];
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // first pixel
            if (h == 0 && w == 0)
            {
                new_image[h][w].rgbtRed = roundf((image[h][w].rgbtRed + image[h][w+1].rgbtRed + image[h+1][w].rgbtRed + image[h+1][w+1].rgbtRed) / (float) 4);
                new_image[h][w].rgbtGreen = roundf((image[h][w].rgbtGreen + image[h][w+1].rgbtGreen + image[h+1][w].rgbtGreen + image[h+1][w+1].rgbtGreen) / (float) 4);
                new_image[h][w].rgbtBlue = roundf((image[h][w].rgbtBlue + image[h][w+1].rgbtBlue + image[h+1][w].rgbtBlue + image[h+1][w+1].rgbtBlue) / (float) 4);
            }
            // Last row Left
            else if (h == height - 1 && w == 0)
            {
                new_image[h][w].rgbtRed = roundf((image[h][w].rgbtRed + image[h-1][w].rgbtRed + image[h-1][w+1].rgbtRed + image[h][w+1].rgbtRed) / (float) 4);
                new_image[h][w].rgbtGreen = roundf((image[h][w].rgbtGreen + image[h-1][w].rgbtGreen + image[h-1][w+1].rgbtGreen + image[h][w+1].rgbtGreen) / (float) 4);
                new_image[h][w].rgbtBlue = roundf((image[h][w].rgbtBlue + image[h-1][w].rgbtBlue + image[h-1][w+1].rgbtBlue + image[h][w+1].rgbtBlue) / (float) 4);
            }
            // first row right
            else if (h == 0 && w == width - 1)
            {
                new_image[h][w].rgbtRed = roundf((image[h][w].rgbtRed + image[h][w-1].rgbtRed + image[h+1][w-1].rgbtRed + image[h+1][w].rgbtRed) / (float) 4);
                new_image[h][w].rgbtGreen = roundf((image[h][w].rgbtGreen + image[h][w-1].rgbtGreen + image[h+1][w-1].rgbtGreen + image[h+1][w].rgbtGreen) / (float) 4);
                new_image[h][w].rgbtBlue = roundf((image[h][w].rgbtBlue + image[h][w-1].rgbtBlue + image[h+1][w-1].rgbtBlue + image[h+1][w].rgbtBlue) / (float) 4);
            }
            // Last row right
            else if (h == height - 1 && w == width - 1)
            {
                new_image[h][w].rgbtRed = roundf((image[h][w].rgbtRed + image[h-1][w].rgbtRed + image[h-1][w-1].rgbtRed + image[h][w-1].rgbtRed) / (float) 4);
                new_image[h][w].rgbtGreen = roundf((image[h][w].rgbtGreen + image[h-1][w].rgbtGreen + image[h-1][w-1].rgbtGreen + image[h][w-1].rgbtGreen) / (float) 4);
                new_image[h][w].rgbtBlue = roundf((image[h][w].rgbtBlue + image[h-1][w].rgbtBlue + image[h-1][w-1].rgbtBlue + image[h][w-1].rgbtBlue) / (float) 4);
            }
            // top row
            else if (h == 0)
            {
                new_image[h][w].rgbtRed = roundf((image[h][w].rgbtRed + image[h][w-1].rgbtRed + image[h][w+1].rgbtRed + image[h+1][w-1].rgbtRed + image[h+1][w].rgbtRed + image[h+1][w+1].rgbtRed) / (float) 6);
                new_image[h][w].rgbtGreen = roundf((image[h][w].rgbtGreen + image[h][w-1].rgbtGreen + image[h][w+1].rgbtGreen + image[h+1][w-1].rgbtGreen + image[h+1][w].rgbtGreen + image[h+1][w+1].rgbtGreen) / (float) 6);
                new_image[h][w].rgbtBlue = roundf((image[h][w].rgbtBlue + image[h][w-1].rgbtBlue + image[h][w+1].rgbtBlue + image[h+1][w-1].rgbtBlue + image[h+1][w].rgbtBlue + image[h+1][w+1].rgbtBlue) / (float) 6);
            }
            // bottom row
            else if (h == height -1)
            {
                new_image[h][w].rgbtRed = roundf((image[h][w].rgbtRed + image[h][w-1].rgbtRed + image[h][w+1].rgbtRed + image[h-1][w-1].rgbtRed + image[h-1][w].rgbtRed + image[h-1][w+1].rgbtRed) / (float) 6);
                new_image[h][w].rgbtGreen = roundf((image[h][w].rgbtGreen + image[h][w-1].rgbtGreen + image[h][w+1].rgbtGreen + image[h-1][w-1].rgbtGreen + image[h-1][w].rgbtGreen + image[h-1][w+1].rgbtGreen) / (float) 6);
                new_image[h][w].rgbtBlue = roundf((image[h][w].rgbtBlue + image[h][w-1].rgbtBlue + image[h][w+1].rgbtBlue + image[h-1][w-1].rgbtBlue + image[h-1][w].rgbtBlue + image[h-1][w+1].rgbtBlue) / (float) 6);
            }
            // left column
            else if (w == 0)
            {
                new_image[h][w].rgbtRed = roundf((image[h][w].rgbtRed + image[h-1][w].rgbtRed + image[h+1][w].rgbtRed + image[h-1][w+1].rgbtRed + image[h][w+1].rgbtRed + image[h+1][w+1].rgbtRed) / (float) 6);
                new_image[h][w].rgbtGreen = roundf((image[h][w].rgbtGreen + image[h-1][w].rgbtGreen + image[h+1][w].rgbtGreen + image[h-1][w+1].rgbtGreen + image[h][w+1].rgbtGreen + image[h+1][w+1].rgbtGreen) / (float) 6);
                new_image[h][w].rgbtBlue = roundf((image[h][w].rgbtBlue + image[h-1][w].rgbtBlue + image[h+1][w].rgbtBlue + image[h-1][w+1].rgbtBlue + image[h][w+1].rgbtBlue + image[h+1][w+1].rgbtBlue) / (float) 6);
            }
            // right column
            else if (w == width - 1)
            {
                new_image[h][w].rgbtRed = roundf((image[h][w].rgbtRed + image[h-1][w].rgbtRed + image[h+1][w].rgbtRed + image[h-1][w-1].rgbtRed + image[h][w-1].rgbtRed + image[h+1][w-1].rgbtRed) / (float) 6);
                new_image[h][w].rgbtGreen = roundf((image[h][w].rgbtGreen + image[h-1][w].rgbtGreen + image[h+1][w].rgbtGreen + image[h-1][w-1].rgbtGreen + image[h][w-1].rgbtGreen + image[h+1][w-1].rgbtGreen) / (float) 6);
                new_image[h][w].rgbtBlue = roundf((image[h][w].rgbtBlue + image[h-1][w].rgbtBlue + image[h+1][w].rgbtBlue + image[h-1][w-1].rgbtBlue + image[h][w-1].rgbtBlue + image[h+1][w-1].rgbtBlue) / (float) 6);
            }
            else
            {
                new_image[h][w].rgbtRed = roundf((image[h][w].rgbtRed + image[h][w-1].rgbtRed + image[h][w+1].rgbtRed +
                                            image[h-1][w].rgbtRed + image[h-1][w-1].rgbtRed + image[h-1][w+1].rgbtRed +
                                            image[h+1][w].rgbtRed + image[h+1][w-1].rgbtRed + image[h+1][w+1].rgbtRed) / (float) 9);
                new_image[h][w].rgbtGreen = roundf((image[h][w].rgbtGreen + image[h][w-1].rgbtGreen + image[h][w+1].rgbtGreen +
                                            image[h-1][w].rgbtGreen + image[h-1][w-1].rgbtGreen + image[h-1][w+1].rgbtGreen +
                                            image[h+1][w].rgbtGreen + image[h+1][w-1].rgbtGreen + image[h+1][w+1].rgbtGreen) / (float) 9);
                new_image[h][w].rgbtBlue = roundf((image[h][w].rgbtBlue + image[h][w-1].rgbtBlue + image[h][w+1].rgbtBlue +
                                            image[h-1][w].rgbtBlue + image[h-1][w-1].rgbtBlue + image[h-1][w+1].rgbtBlue +
                                            image[h+1][w].rgbtBlue + image[h+1][w-1].rgbtBlue + image[h+1][w+1].rgbtBlue) / (float) 9);
            }
        }
    }

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
          image[h][w] = new_image[h][w];
        }
    }


    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // if (h == 0 || h == height -1 || w == 0 || w == width -1)
            // {
            //     new_image[h][w].rgbtRed = 0;
            //     new_image[h][w].rgbtGreen = 0;
            //     new_image[h][w].rgbtBlue = 0;
            // }
            // first pixel
            if (h == 0 && w == 0)
            {
                float x_red_value = image[h][w+1].rgbtRed * 2 + image[h+1][w+1].rgbtRed;
                float y_red_value = image[h+1][w].rgbtRed * 2 + image[h+1][w+1].rgbtRed;
                float x_green_value = image[h][w+1].rgbtGreen * 2 + image[h+1][w+1].rgbtGreen;
                float y_green_value = image[h+1][w].rgbtGreen * 2 + image[h+1][w+1].rgbtGreen;
                float x_blue_value = image[h][w+1].rgbtBlue * 2 + image[h+1][w+1].rgbtBlue;
                float y_blue_value = image[h+1][w].rgbtBlue * 2 + image[h+1][w+1].rgbtBlue;

                // calculate sobel

                new_image[h][w].rgbtRed = calculateSobel(x_red_value, y_red_value);
                new_image[h][w].rgbtGreen = calculateSobel(x_green_value, y_green_value);
                new_image[h][w].rgbtBlue = calculateSobel(x_blue_value, y_blue_value);
            }
            // Last row Left
            else if (h == height - 1 && w == 0)
            {
                float x_red_value = image[h-1][w+1].rgbtRed + image[h][w+1].rgbtRed * 2;
                float y_red_value = image[h-1][w].rgbtRed * -2 + image[h-1][w+1].rgbtRed * -1;
                float x_green_value = image[h-1][w+1].rgbtGreen + image[h][w+1].rgbtGreen * 2;
                float y_green_value = image[h-1][w].rgbtGreen * -2 + image[h-1][w+1].rgbtGreen * -1;
                float x_blue_value = image[h-1][w+1].rgbtBlue + image[h][w+1].rgbtBlue * 2;
                float y_blue_value = image[h-1][w].rgbtBlue * -2 + image[h-1][w+1].rgbtBlue * -1;
                // calculate sobel

                new_image[h][w].rgbtRed = calculateSobel(x_red_value, y_red_value);
                new_image[h][w].rgbtGreen = calculateSobel(x_green_value, y_green_value);
                new_image[h][w].rgbtBlue = calculateSobel(x_blue_value, y_blue_value);
            }
            // first row right
            else if (h == 0 && w == width - 1)
            {
                float x_red_value = image[h][w-1].rgbtRed * -2+ image[h+1][w-1].rgbtRed * -1;
                float y_red_value = image[h+1][w-1].rgbtRed * 2 + image[h+1][w].rgbtRed;
                float x_green_value = image[h][w-1].rgbtGreen * -2+ image[h+1][w-1].rgbtGreen * -1;
                float y_green_value = image[h+1][w-1].rgbtGreen * 2 + image[h+1][w].rgbtGreen;
                float x_blue_value = image[h][w-1].rgbtBlue * -2+ image[h+1][w-1].rgbtBlue * -1;
                float y_blue_value = image[h+1][w-1].rgbtBlue * 2 + image[h+1][w].rgbtBlue;
                // calculate sobel

                new_image[h][w].rgbtRed = calculateSobel(x_red_value, y_red_value);
                new_image[h][w].rgbtGreen = calculateSobel(x_green_value, y_green_value);
                new_image[h][w].rgbtBlue = calculateSobel(x_blue_value, y_blue_value);
            }
            // Last row right
            else if (h == height - 1 && w == width - 1)
            {
                float x_red_value = image[h-1][w-1].rgbtRed * -1 + image[h][w-1].rgbtRed * -2;
                float y_red_value = image[h-1][w-1].rgbtRed * -1 + image[h-1][w].rgbtRed * -2;
                float x_green_value = image[h-1][w-1].rgbtGreen * -1 + image[h][w-1].rgbtGreen * -2;
                float y_green_value = image[h-1][w-1].rgbtGreen * -1 + image[h-1][w].rgbtGreen * -2;
                float x_blue_value = image[h-1][w-1].rgbtBlue * -1 + image[h][w-1].rgbtBlue * -2;
                float y_blue_value = image[h-1][w-1].rgbtBlue * -1 + image[h-1][w].rgbtBlue * -2;
                // calculate sobel

                new_image[h][w].rgbtRed = calculateSobel(x_red_value, y_red_value);
                new_image[h][w].rgbtGreen = calculateSobel(x_green_value, y_green_value);
                new_image[h][w].rgbtBlue = calculateSobel(x_blue_value, y_blue_value);
            }
            // top row
            else if (h == 0)
            {
                float x_red_value = image[h][w-1].rgbtRed * -2 + image[h][w+1].rgbtRed * 2 + image[h-1][w-1].rgbtRed * -1 + image[h-1][w+1].rgbtRed;
                float y_red_value = image[h+1][w-1].rgbtRed + image[h+1][w].rgbtRed * 2 + image[h+1][w].rgbtRed;
                float x_green_value = image[h][w-1].rgbtGreen * -2 + image[h][w+1].rgbtGreen * 2 + image[h-1][w-1].rgbtGreen * -1 + image[h-1][w+1].rgbtGreen;
                float y_green_value = image[h+1][w-1].rgbtGreen + image[h+1][w].rgbtGreen * 2 + image[h+1][w].rgbtGreen;
                float x_blue_value = image[h][w-1].rgbtBlue * -2 + image[h][w+1].rgbtBlue * 2 + image[h-1][w-1].rgbtBlue * -1 + image[h-1][w+1].rgbtBlue;
                float y_blue_value = image[h+1][w-1].rgbtBlue + image[h+1][w].rgbtBlue * 2 + image[h+1][w].rgbtBlue;
                // calculate sobel

                new_image[h][w].rgbtRed = calculateSobel(x_red_value, y_red_value);
                new_image[h][w].rgbtGreen = calculateSobel(x_green_value, y_green_value);
                new_image[h][w].rgbtBlue = calculateSobel(x_blue_value, y_blue_value);
            }
            // bottom row
            else if (h == height -1)
            {
                float x_red_value = image[h-1][w-1].rgbtRed * -1 + image[h-1][w+1].rgbtRed + image[h][w-1].rgbtRed * -2 + image[h][w+1].rgbtRed * 2;
                float y_red_value = image[h-1][w-1].rgbtRed * -1 + image[h-1][w].rgbtRed * -2 + image[h-1][w+1].rgbtRed * -1;
                float x_green_value = image[h-1][w-1].rgbtGreen * -1 + image[h-1][w+1].rgbtGreen + image[h][w-1].rgbtGreen * -2 + image[h][w+1].rgbtGreen * 2;
                float y_green_value = image[h-1][w-1].rgbtGreen * -1 + image[h-1][w].rgbtGreen * -2 + image[h-1][w+1].rgbtGreen * -1;
                float x_blue_value = image[h-1][w-1].rgbtBlue * -1 + image[h-1][w+1].rgbtBlue + image[h][w-1].rgbtBlue * -2 + image[h][w+1].rgbtBlue * 2;
                float y_blue_value = image[h-1][w-1].rgbtBlue * -1 + image[h-1][w].rgbtBlue * -2 + image[h-1][w+1].rgbtBlue * -1;
                // calculate sobel

                new_image[h][w].rgbtRed = calculateSobel(x_red_value, y_red_value);
                new_image[h][w].rgbtGreen = calculateSobel(x_green_value, y_green_value);
                new_image[h][w].rgbtBlue = calculateSobel(x_blue_value, y_blue_value);
            }
            // left column
            else if (w == 0)
            {
                float x_red_value = image[h-1][w+1].rgbtRed + image[h][w+1].rgbtRed * 2 + image[h+1][w+1].rgbtRed;
                float y_red_value = image[h-1][w].rgbtRed * -2 + image[h-1][w+1].rgbtRed * -1 + image[h+1][w].rgbtRed * 2 + image[h+1][w+1].rgbtRed;
                float x_green_value = image[h-1][w+1].rgbtGreen + image[h][w+1].rgbtGreen * 2 + image[h+1][w+1].rgbtGreen;
                float y_green_value = image[h-1][w].rgbtGreen * -2 + image[h-1][w+1].rgbtGreen * -1 + image[h+1][w].rgbtGreen * 2 + image[h+1][w+1].rgbtGreen;
                float x_blue_value = image[h-1][w+1].rgbtBlue + image[h][w+1].rgbtBlue * 2 + image[h+1][w+1].rgbtBlue;
                float y_blue_value = image[h-1][w].rgbtBlue * -2 + image[h-1][w+1].rgbtBlue * -1 + image[h+1][w].rgbtBlue * 2 + image[h+1][w+1].rgbtBlue;
                // calculate sobel

                new_image[h][w].rgbtRed = calculateSobel(x_red_value, y_red_value);
                new_image[h][w].rgbtGreen = calculateSobel(x_green_value, y_green_value);
                new_image[h][w].rgbtBlue = calculateSobel(x_blue_value, y_blue_value);
            }
            // right column
            else if (w == width - 1)
            {
                float x_red_value = image[h-1][w-1].rgbtRed * -1 + image[h][w-1].rgbtRed * -2 + image[h+1][w-1].rgbtRed * -1;
                float y_red_value = image[h-1][w-1].rgbtRed * -1 + image[h-1][w].rgbtRed * -2 + image[h+1][w-1].rgbtRed + image[h+1][w].rgbtRed * 2;
                float x_green_value = image[h-1][w-1].rgbtGreen * -1 + image[h][w-1].rgbtGreen * -2 + image[h+1][w-1].rgbtGreen * -1;
                float y_green_value = image[h-1][w-1].rgbtGreen * -1 + image[h-1][w].rgbtGreen * -2 + image[h+1][w-1].rgbtGreen + image[h+1][w].rgbtGreen * 2;
                float x_blue_value = image[h-1][w-1].rgbtBlue * -1 + image[h][w-1].rgbtBlue * -2 + image[h+1][w-1].rgbtBlue * -1;
                float y_blue_value = image[h-1][w-1].rgbtBlue * -1 + image[h-1][w].rgbtBlue * -2 + image[h+1][w-1].rgbtBlue + image[h+1][w].rgbtBlue * 2;
                // calculate sobel

                new_image[h][w].rgbtRed = calculateSobel(x_red_value, y_red_value);
                new_image[h][w].rgbtGreen = calculateSobel(x_green_value, y_green_value);
                new_image[h][w].rgbtBlue = calculateSobel(x_blue_value, y_blue_value);
            }

            else {
                // Get values
                float x_red_value = image[h+1][w+1].rgbtRed + image[h][w+1].rgbtRed * 2;
                float y_red_value = image[h-1][w].rgbtRed * -2 + image[h-1][w+1].rgbtRed * -1;
                float x_green_value = image[h+1][w+1].rgbtGreen + image[h][w+1].rgbtGreen * 2;
                float y_green_value = image[h-1][w].rgbtGreen * -2 + image[h-1][w+1].rgbtGreen * -1;
                float x_blue_value = image[h+1][w+1].rgbtBlue + image[h][w+1].rgbtBlue * 2;
                float y_blue_value = image[h-1][w].rgbtBlue * -2 + image[h-1][w+1].rgbtBlue * -1;
                // calculate sobel

                new_image[h][w].rgbtRed = calculateSobel(x_red_value, y_red_value);
                new_image[h][w].rgbtGreen = calculateSobel(x_green_value, y_green_value);
                new_image[h][w].rgbtBlue = calculateSobel(x_blue_value, y_blue_value);
            }
        }
    }

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
          image[h][w] = new_image[h][w];
        }
    }
    return;
}

float calculateSobel(float x, float y)
{
    float sobel = sqrt(x *x + y * y);
    if (sobel > 255)
    {
        return 255;
    }
    else if (sobel < 1)
    {
        return 0;
    }
    else
    {
        return roundf(sobel);
    }
}
