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
            else if (i - 1 < 0 && j - 1 < 0)
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
            else if (i - 1 < 0 && j - 1 >= 0 && j + 1 < width)
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
            else if (i - 1 < 0 && j - 1 > 0 && i + 1 < height && j + 1 >= width)
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
            else if (j - 1 < 0 && i - 1 >= 0 && i + 1 < height)
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
            else if (j + 1 >= width && i - 1 >= 0 && i + 1 < height)
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
            else if (j - 1 < 0 && i + 1 >= height)
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
            else if (j - 1 >= 0 && i + 1 >= height && j + 1 < width)
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
            else if (i + 1 >= height && j + 1 >= width)
            {
                for (int a = i - 1; a <= i; a++)
                {
                    for (int b = j - 1; b <= j; b++)
                    {
                        sumBlue += trans[a][b].rgbtBlue;
                        sumGreen += trans[a][b].rgbtGreen;
                        sumRed += trans[a][b].rgbtRed;

                        count = 4;
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
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
            float ar = 0;
            float ag = 0; 
            float ab = 0;
            
            float br = 0;
            float bg = 0;
            float bb = 0;
            
            float cr = 0;
            float cg = 0;
            float cb = 0;
            
            float dr = 0;
            float dg = 0;
            float db = 0;
            
            float er = 0;
            float eg = 0;
            float eb = 0;
            
            float fr = 0;
            float fg = 0;
            float fb = 0;
            
            float gr = 0;
            float gg = 0;
            float gb = 0;
            
            float hr = 0;
            float hg = 0;
            float hb = 0;
            
            float ir = 0;
            float ig = 0;
            float ib = 0;
            
            if (i - 1 < 0 && j - 1 < 0)
            {
                er = trans[i][j].rgbtRed;
                eg = trans[i][j].rgbtGreen;
                eb = trans[i][j].rgbtBlue;
            
                fr = trans[i][j + 1].rgbtRed;
                fg = trans[i][j + 1].rgbtGreen;
                fb = trans[i][j + 1].rgbtBlue;
                
                hr = trans[i + 1][j].rgbtRed;
                hg = trans[i + 1][j].rgbtGreen;
                hb = trans[i + 1][j].rgbtBlue;
            
                ir = trans[i + 1][j + 1].rgbtRed;
                ig = trans[i + 1][j + 1].rgbtGreen;
                ib = trans[i + 1][j + 1].rgbtBlue;
            }
            else if (i - 1 < 0 && j - 1 >= 0 && j + 1 < height)
            {
                dr = trans[i][j - 1].rgbtRed;
                dg = trans[i][j - 1].rgbtGreen;
                db = trans[i][j - 1].rgbtBlue;
                
                er = trans[i][j].rgbtRed;
                eg = trans[i][j].rgbtGreen;
                eb = trans[i][j].rgbtBlue;
            
                fr = trans[i][j + 1].rgbtRed;
                fg = trans[i][j + 1].rgbtGreen;
                fb = trans[i][j + 1].rgbtBlue;
                
                gr = trans[i + 1][j - 1].rgbtRed;
                gg = trans[i + 1][j - 1].rgbtGreen;
                gb = trans[i + 1][j - 1].rgbtBlue;
                
                hr = trans[i + 1][j].rgbtRed;
                hg = trans[i + 1][j].rgbtGreen;
                hb = trans[i + 1][j].rgbtBlue;
            
                ir = trans[i + 1][j + 1].rgbtRed;
                ig = trans[i + 1][j + 1].rgbtGreen;
                ib = trans[i + 1][j + 1].rgbtBlue;
            }
            else if (i - 1 < 0 && j + 1 >= width)
            {  
                dr = trans[i][j - 1].rgbtRed;
                dg = trans[i][j - 1].rgbtGreen;
                db = trans[i][j - 1].rgbtBlue;
                
                er = trans[i][j].rgbtRed;
                eg = trans[i][j].rgbtGreen;
                eb = trans[i][j].rgbtBlue;
                
                gr = trans[i + 1][j - 1].rgbtRed;
                gg = trans[i + 1][j - 1].rgbtGreen;
                gb = trans[i + 1][j - 1].rgbtBlue;
                
                hr = trans[i + 1][j].rgbtRed;
                hg = trans[i + 1][j].rgbtGreen;
                hb = trans[i + 1][j].rgbtBlue;
            }
            else if (j - 1 < 0 && i + 1 < height && i - 1 >= 0)
            {
                br = trans[i - 1][j].rgbtRed;
                bg = trans[i - 1][j].rgbtGreen;
                bb = trans[i - 1][j].rgbtBlue;
                
                cr = trans[i - 1][j + 1].rgbtRed;
                cg = trans[i - 1][j + 1].rgbtGreen;
                cb = trans[i - 1][j + 1].rgbtBlue;
                
                er = trans[i][j].rgbtRed;
                eg = trans[i][j].rgbtGreen;
                eb = trans[i][j].rgbtBlue;
                
                fr = trans[i][j + 1].rgbtRed;
                fg = trans[i][j + 1].rgbtGreen;
                fb = trans[i][j + 1].rgbtBlue;
                
                hr = trans[i + 1][j].rgbtRed;
                hg = trans[i + 1][j].rgbtGreen;
                hb = trans[i + 1][j].rgbtBlue;
            
                ir = trans[i + 1][j + 1].rgbtRed;
                ig = trans[i + 1][j + 1].rgbtGreen;
                ib = trans[i + 1][j + 1].rgbtBlue;
            }
            else if (j + 1 >= height && i + 1 < height && i - 1 >= 0)
            {
                ar = trans[i - 1][j - 1].rgbtRed;
                ag = trans[i - 1][j - 1].rgbtGreen; 
                ab = trans[i - 1][j - 1].rgbtBlue;
            
                br = trans[i - 1][j].rgbtRed;
                bg = trans[i - 1][j].rgbtGreen;
                bb = trans[i - 1][j].rgbtBlue;
                
                dr = trans[i][j - 1].rgbtRed;
                dg = trans[i][j - 1].rgbtGreen;
                db = trans[i][j - 1].rgbtBlue;
                
                er = trans[i][j].rgbtRed;
                eg = trans[i][j].rgbtGreen;
                eb = trans[i][j].rgbtBlue;
                
                gr = trans[i + 1][j - 1].rgbtRed;
                gg = trans[i + 1][j - 1].rgbtGreen;
                gb = trans[i + 1][j - 1].rgbtBlue;
                
                hr = trans[i + 1][j].rgbtRed;
                hg = trans[i + 1][j].rgbtGreen;
                hb = trans[i + 1][j].rgbtBlue;
            }    
            else if (i + 1 >= height && j - 1 < 0)
            {
                br = trans[i - 1][j].rgbtRed;
                bg = trans[i - 1][j].rgbtGreen;
                bb = trans[i - 1][j].rgbtBlue;
                
                cr = trans[i - 1][j + 1].rgbtRed;
                cg = trans[i - 1][j + 1].rgbtGreen;
                cb = trans[i - 1][j + 1].rgbtBlue;
                
                er = trans[i][j].rgbtRed;
                eg = trans[i][j].rgbtGreen;
                eb = trans[i][j].rgbtBlue;
                
                fr = trans[i][j + 1].rgbtRed;
                fg = trans[i][j + 1].rgbtGreen;
                fb = trans[i][j + 1].rgbtBlue;
            }
            else if (i + 1 >= height && j - 1 >= 0 && j + 1 < width)
            {
                ar = trans[i - 1][j - 1].rgbtRed;
                ag = trans[i - 1][j - 1].rgbtGreen; 
                ab = trans[i - 1][j - 1].rgbtBlue;
            
                br = trans[i - 1][j].rgbtRed;
                bg = trans[i - 1][j].rgbtGreen;
                bb = trans[i - 1][j].rgbtBlue;
                
                cr = trans[i - 1][j + 1].rgbtRed;
                cg = trans[i - 1][j + 1].rgbtGreen;
                cb = trans[i - 1][j + 1].rgbtBlue;
                
                dr = trans[i][j - 1].rgbtRed;
                dg = trans[i][j - 1].rgbtGreen;
                db = trans[i][j - 1].rgbtBlue;
                
                er = trans[i][j].rgbtRed;
                eg = trans[i][j].rgbtGreen;
                eb = trans[i][j].rgbtBlue;
                
                fr = trans[i][j + 1].rgbtRed;
                fg = trans[i][j + 1].rgbtGreen;
                fb = trans[i][j + 1].rgbtBlue;
            }
            else if (i + 1 >= height && j + 1 >= width)
            {
                ar = trans[i - 1][j - 1].rgbtRed;
                ag = trans[i - 1][j - 1].rgbtGreen; 
                ab = trans[i - 1][j - 1].rgbtBlue;
            
                br = trans[i - 1][j].rgbtRed;
                bg = trans[i - 1][j].rgbtGreen;
                bb = trans[i - 1][j].rgbtBlue;
                
                dr = trans[i][j - 1].rgbtRed;
                dg = trans[i][j - 1].rgbtGreen;
                db = trans[i][j - 1].rgbtBlue;
                
                er = trans[i][j].rgbtRed;
                eg = trans[i][j].rgbtGreen;
                eb = trans[i][j].rgbtBlue;
            }
            else if (i - 1 >= 0 && i + 1 < height && j + 1 < width && j - 1 >= 0)
            {
                ar = trans[i - 1][j - 1].rgbtRed;
                ag = trans[i - 1][j - 1].rgbtGreen; 
                ab = trans[i - 1][j - 1].rgbtBlue;
            
                br = trans[i - 1][j].rgbtRed;
                bg = trans[i - 1][j].rgbtGreen;
                bb = trans[i - 1][j].rgbtBlue;
                
                cr = trans[i - 1][j + 1].rgbtRed;
                cg = trans[i - 1][j + 1].rgbtGreen;
                cb = trans[i - 1][j + 1].rgbtBlue;
                
                dr = trans[i][j - 1].rgbtRed;
                dg = trans[i][j - 1].rgbtGreen;
                db = trans[i][j - 1].rgbtBlue;
                
                er = trans[i][j].rgbtRed;
                eg = trans[i][j].rgbtGreen;
                eb = trans[i][j].rgbtBlue;
                
                fr = trans[i][j + 1].rgbtRed;
                fg = trans[i][j + 1].rgbtGreen;
                fb = trans[i][j + 1].rgbtBlue;
                
                gr = trans[i + 1][j - 1].rgbtRed;
                gg = trans[i + 1][j - 1].rgbtGreen;
                gb = trans[i + 1][j - 1].rgbtBlue;
                
                hr = trans[i + 1][j].rgbtRed;
                hg = trans[i + 1][j].rgbtGreen;
                hb = trans[i + 1][j].rgbtBlue;
            
                ir = trans[i + 1][j + 1].rgbtRed;
                ig = trans[i + 1][j + 1].rgbtGreen;
                ib = trans[i + 1][j + 1].rgbtBlue;
            }
            
            float GxRed = cr - ar - (2 * dr) + (2 * fr) - gr + ir;
            float GxGreen = cg - ag - (2 * dg) + (2 * fg) - gg + ig;
            float GxBlue = cb - ab - (2 * db) + (2 * fb) - gb + ib;
            
            float GyRed = gr + (2 * hr) + ir - ar - (2 * br) - cr;
            float GyGreen = gg + (2 * hg) + ig - ag - (2 * bg) - cg;
            float GyBlue = gb + (2 * hb) + ib - ab - (2 * bb) - cb;
            
            int Red = round(sqrt((GxRed * GxRed) + (GyRed * GyRed)));
            if (Red > 255)
            {
                Red = 255;
            }
            int Green = round(sqrt((GxGreen * GxGreen) + (GyGreen * GyGreen)));
            if (Green > 255)
            {
                Green = 255;
            }
            int Blue = round(sqrt((GxBlue * GxBlue) + (GyBlue * GyBlue)));
            if (Blue > 255)
            {
                Blue = 255;
            }
            
            image[i][j].rgbtRed = Red;
            image[i][j].rgbtGreen = Green;
            image[i][j].rgbtBlue = Blue;
        }
    }
    return;
}
