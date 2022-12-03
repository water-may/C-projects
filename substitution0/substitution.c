#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int check = 0; //check to check the repitation count to.
    bool a = true; //for checking if character is repeated or not.
    bool c = true; //to check if character is alphabetic or not.
    string key = argv[1];

    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (!isalpha(argv[1][i]))
            {
                c = false;
            }
        }
    }
    if (c == false) //checking duplicate character.
    {
        printf("Key must only contain alphabetic character\n");
        return 1;
    }
    else
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isupper(argv[1][i]))
            {
                argv[1][i] += 32;
            }
            for (int j = 0; j < strlen(argv[1]); j++)
            {
                if (argv[1][i] == argv[1][j])
                {
                    check++;
                    if (check > strlen(argv[1]))
                    {
                        a = false;
                    }
                }
            }
        }
    }
    if (a == false)
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }
    else
    {
         string text = get_string("plaintext: ");
         printf("ciphertext: ");
         for (int i = 0; i  < strlen(text); i++)
         {
             if (isupper(text[i]))
             {
                 int j = text[i] - 65;
                 printf("%c", toupper(key[j]));
             }
             else if (islower(text[i]))
             {
                 int j = text[i] - 97;
                 printf("%c", key[j]);
             }
             else
             {
                 printf("%c", text[i]);
             }
         }
         printf("\n");
    }
}

