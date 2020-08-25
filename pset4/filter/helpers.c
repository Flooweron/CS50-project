#include "helpers.h"
#include <math.h>
#include <cs50.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{   
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int avr = round((pixel.rgbtBlue + pixel.rgbtGreen + pixel.rgbtRed) / 3.0);
            image[i][j].rgbtBlue = image[i][j].rgbtRed = image[i][j].rgbtGreen = avr;
        }
    }
    return;
}

int backTo(int value)
{
    return value > 255 ? 255 : value;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int orig_red = pixel.rgbtRed;
            int orig_green = pixel.rgbtGreen;
            int orig_blue = pixel.rgbtBlue;
            image[i][j].rgbtRed = backTo(round(.393 * orig_red + .769 * orig_green + .189 * orig_blue));
            image[i][j].rgbtGreen = backTo(round(.349 * orig_red + .686 * orig_green + .168 * orig_blue));
            image[i][j].rgbtBlue = backTo(round(.272 * orig_red + .534 * orig_green + .131 * orig_blue));
        }
    }
    return;
}

void swap(RGBTRIPLE *pixel1, RGBTRIPLE *pixel2)
{
    RGBTRIPLE temp = *pixel1;
    *pixel1 = *pixel2;
    *pixel2 = temp;
}
// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            swap(&image[i][j], &image[i][width - 1 - j]);
        }
    }
    return;
}

bool is_valid_pixel(int i, int j, int height, int width)
{
    return i >= 0 && i < height && j >= 0 && j < width ;
}

RGBTRIPLE get_blurred_pixel(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    int redValue, blueValue, greenValue; redValue = blueValue = greenValue = 0;
    int numValPixels = 0;
    for (int ai = -1; ai <= 1; ai++)
    {
        for (int aj = -1; aj <= 1; aj++)
        {
            int new_i = i + ai;
            int new_j = j + aj;
            if (is_valid_pixel(new_i, new_j, height, width))
            {
                numValPixels++;
                redValue += image[new_i][new_j].rgbtRed;
                blueValue += image[new_i][new_j].rgbtBlue;
                greenValue += image[new_i][new_j].rgbtGreen;
            }
        }
    }
    RGBTRIPLE blurred_pixel;
    blurred_pixel.rgbtRed = round((float) redValue / numValPixels);
    blurred_pixel.rgbtBlue = round((float) blueValue / numValPixels);
    blurred_pixel.rgbtGreen = round((float) greenValue / numValPixels);
    return blurred_pixel;
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            new_image[i][j] = get_blurred_pixel(i, j, height, width, image);
        }
    }
    
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            image[i][j] = new_image[i][j];
}
