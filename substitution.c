#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY no argv2\n");
        return 1;
    }
    // printf("lenght: %i\n", (int) strlen(argv[1]));

    // Check Key

    if (!((int) strlen(argv[1]) == 26))
        {
            printf("Usage: ./substitution KEY lenght\n");
            return 1;
        }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./substitution KEY is alpha\n");
            return 1;
        }
        int letter_appears = 0;
        for (int a = 0; a < n; a++)
        {
            if (argv[1][i] == argv[1][a])
            {
                letter_appears++;
            }
        }
        if (letter_appears > 1)
        {
            printf("Usage: ./substitution KEY letter appears\n");
            return 1;
        }
    }

    string key_upper = argv[1];

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        key_upper[i] = toupper(key_upper[i]);
    }

    printf("Upper: %s", key_upper);
    // printf("key: %s\n", key);

    // Getting text
    string text = get_string("plaintext: ");

    // Encrypting

    printf("ciphertext: ");

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            int num = (int) text[i] - 97;
            printf("%c", (key_upper[num] + 32));
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            int num = (int) text[i] - 65;
            printf("%c", key_upper[num]);
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
