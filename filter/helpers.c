#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float a = image[i][j].rgbtRed;
            float b = image[i][j].rgbtGreen;
            float c = image[i][j].rgbtBlue;
            float avga = (a + b + c) / 3;
            int avg = round(avga);

            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float a = image[i][j].rgbtRed;
            float b = image[i][j].rgbtGreen;
            float c = image[i][j].rgbtBlue;
            
            float Red = (0.393 * a) + (0.769 * b) + (0.189 * c);
            if (round(Red) > 255)
            {
                Red = 255;
            }
            float Green = (0.349 * a) + (0.686 * b) + (0.168 * c);
            if (round(Green) > 255)
            {
                Green = 255;
            }
            float Blue = (0.272 * a) + (0.534 * b) + (0.131 * c);
            if (round(Blue) > 255)
            {
                Blue = 255;
            }

            image[i][j].rgbtRed = round(Red);
            image[i][j].rgbtGreen = round(Green);
            image[i][j].rgbtBlue = round(Blue);

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        int k = 0;
        for (int j = width - 1 ; j >= width / 2; j--)
        {
            int aa = image[i][k].rgbtRed;
            int ab = image[i][k].rgbtGreen;
            int ac = image[i][k].rgbtBlue;


            int ba = image[i][j].rgbtRed;
            int bb = image[i][j].rgbtGreen;
            int bc = image[i][j].rgbtBlue;

            image[i][k].rgbtRed = ba;
            image[i][k].rgbtGreen = bb;
            image[i][k].rgbtBlue = bc;

            image[i][j].rgbtRed = aa;
            image[i][j].rgbtGreen = ab;
            image[i][j].rgbtBlue = ac;
            k++;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE trans[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            trans[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumBlue;
            int sumGreen;
            int sumRed;
            float count = 0.0 ;

            sumBlue = sumGreen = sumRed = 0;
            
            //mid
            if (i - 1 >= 0 && j - 1 >= 0 && i + 1 < height && j + 1 < width)
            {
                for (int a = i - 1; a < i + 2; a++)
                {
                    for (int b = j - 1; b < j + 2; b++)
                    {
                        sumBlue += trans[a][b].rgbtBlue;
                        sumGreen += trans[a][b].rgbtGreen;
                        sumRed += trans[a][b].rgbtRed;

                        count = 9.0;
                    }
                }
            }
            else if (i - 1 < 0 && j - 1 < 0) //top left
            {
                for (int a = i; a < i + 2; a++)
                {
                    for (int b = j; b < j + 2; b++)
                    {
                        sumBlue += trans[a][b].rgbtBlue;
                        sumGreen += trans[a][b].rgbtGreen;
                        sumRed += trans[a][b].rgbtRed;

                        count = 4.0;
                    }
                }
            }
            else if (i - 1 < 0 && j - 1 >= 0 && j + 1 < width) //top mid
            {
                for (int a = i; a < i + 2; a++)
                {
                    for (int b = j - 1; b < j + 2; b++)
                    {
                        sumBlue += trans[a][b].rgbtBlue;
                        sumGreen += trans[a][b].rgbtGreen;
                        sumRed += trans[a][b].rgbtRed;

                        count = 6.0;
                    }
                }
            }
            else if (i - 1 < 0 && j - 1 > 0 && i + 1 < height && j + 1 >= width) //top right
            {
                for (int a = i; a < i + 2; a++)
                {
                    for (int b = j - 1; b < j + 1; b++)
                    {
                        sumBlue += trans[a][b].rgbtBlue;
                        sumGreen += trans[a][b].rgbtGreen;
                        sumRed += trans[a][b].rgbtRed;

                        count = 4.0;
                    }
                }
            }
            else if (j - 1 < 0 && i - 1 >= 0 && i + 1 < height) //left mid
            {
                for (int a = i - 1; a < i + 2; a++)
                {
                    for (int b = j; b < j + 2; b++)
                    {
                        sumBlue += trans[a][b].rgbtBlue;
                        sumGreen += trans[a][b].rgbtGreen;
                        sumRed += trans[a][b].rgbtRed;

                        count = 6.0;
                    }
                }
            }
            else if (j + 1 >= width && i - 1 >= 0 && i + 1 < height) //right mid
            {
                for (int a = i - 1; a <= i + 1; a++)
                {
                    for (int b = j - 1; b <= j; b++)
                    {
                        sumBlue += trans[a][b].rgbtBlue;
                        sumGreen += trans[a][b].rgbtGreen;
                        sumRed += trans[a][b].rgbtRed;

                        count = 6.0;
                    }
                }
            }
            else if (j - 1 < 0 && i + 1 >= height) //buttom left 
            {
                for (int a = i - 1; a <= i; a++)
                {
                    for (int b = j; b <= j + 1; b++)
                    {
                        sumBlue += trans[a][b].rgbtBlue;
                        sumGreen += trans[a][b].rgbtGreen;
                        sumRed += trans[a][b].rgbtRed;

                        count = 4.0;
                    }
                }
            }
            else if (j - 1 >= 0 && i + 1 >= height && j + 1 < width) //buttom mid
            {
                for (int a = i - 1; a <= i; a++)
                {
                    for (int b = j - 1; b < j + 2; b++)
                    {
                        sumBlue += trans[a][b].rgbtBlue;
                        sumGreen += trans[a][b].rgbtGreen;
                        sumRed += trans[a][b].rgbtRed;

                        count = 6.0;
                    }
                }
            }
            else if (i + 1 >= height && j + 1 >= width) //buttom right
            {
                for (int a = i - 1; a <= i; a++)
                {
                    for (int b = j - 1; b <= j; b++)
                    {
                        sumBlue += trans[a][b].rgbtBlue;
                        sumGreen += trans[a][b].rgbtGreen;
                        sumRed += trans[a][b].rgbtRed;

                        count = 4.0;
                    }
                }
            }

            image[i][j].rgbtRed = round(sumRed / count);
            image[i][j].rgbtGreen = round(sumGreen / count);
            image[i][j].rgbtBlue = round(sumBlue / count);

        }
    }

    return;
}
