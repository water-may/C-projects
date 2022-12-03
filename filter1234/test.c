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
