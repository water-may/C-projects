#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int i;
    float letter = 0, sentence = 0, word = 1;
    float L = 0, S = 0;

    string text = get_string("Text: ");

    for (i = 0; i <= strlen(text); i++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            letter++;
        }
        else if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentence++;
        }
        else if (text[i] == 32)
        {
            word++;
        }
    }
    printf("letter: %f\n", letter);
    printf("words: %f\n", word);
    printf("sentence: %f\n", sentence);
    
    L = letter / word * 100;
    printf("%f\n", L);
    S = sentence / word * 100;
    printf("%f\n", S);
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }
}
