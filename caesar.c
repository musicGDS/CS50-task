#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key");
            return 1;
        }
    }

    int key = atoi(argv[1]) % 26;

    if (key < 1)
    {
        printf("Usage: ./caesar key");
        return 1;
    }

    string text = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            if (text[i] + key > 122)
            {
                printf("%c", (96 + ((text[i] + key) % 122)));
            }
            else
            {
                printf("%c", text[i] + key);
            }
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            if (text[i] + key > 90)
            {
                printf("%c", (64 + ((text[i] + key) % 90)));
            }
            else
            {
                printf("%c", text[i] + key);
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
