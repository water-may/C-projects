#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    bool b = true;
    if (argc == 2)
    {
        for (int a = 0; a < strlen(argv[1]); a++)
        {
            if ((argv[1][a] < 64 && argv[1][a] > 91) || (argv[1][a] > 96 && argv[1][a] < 123))
            {
                b = false;
            }
        }
    }
    int more;
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
    }
    else if (argc == 2 && b == true)
    {
        int key = atoi(argv[1]);

        string text = get_string("plaintext:%d: ", key);
        printf("ciphertext: ");
        for (int i = 0; i < strlen(text); i++)
        {
            if (isalpha(text[i]))
            {
                if (isupper(text[i]))
                {
                    text[i] += key;
                    if (text[i] > 90)
                    {
                        do
                        {
                            
                            more = text[i] - 90;
                            text[i] = 64 + more;
                        }
                        while (text[i] > 90);
                        printf("%c", text[i]);

                    }
                    else
                    {
                        printf("%c", text[i]);
                    }
                }
                else
                {
                    int less = text[i] + key;
                    if (less > 122)
                    {
                        do
                        {
                            more = less - 122;
                            less = 96 + more;
                        }
                        while (less > 122);
                        text[i] = less;
                        printf("%c", text[i]);
                    }
                    else
                    {
                        text[i] = less;
                        printf("%c", text[i]);
                    }
                }
            }
            else
            {
                printf("%c", text[i]);
            }
        }

        printf("\n");
        return 0;
    }
    return 1;
}