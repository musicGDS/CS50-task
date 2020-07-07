#include <string.h>
#include <math.h>
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>

// int count_letters(string text);
// int count_words(string text);
// int count_sentences(string text);
void count(string text);

int main(void)
{
    string text = get_string("Text: ");
    count(text);
    return 0;
}


void count(string text)
{
    int letters = 0;
    int words = 1;
    int sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i = i + 1)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            letters++;
        }
        else if (text[i] >= 'A' && text[i] <= 'Z'){
            letters++;
        }
        else if(text[i] == ' ') {
            words++;
        }
        else if(text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentences++;
        }
    }

    float grade = 0.0588 * (100 * letters / words) - 0.296 * (100 * sentences / words) - 15.8;
    // printf("%f\n", grade);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 1 && grade < 16)
    {
        printf("Grade %i\n", (int) round(grade));
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
}


// int count_letters(string text)
// {
//     // char *preparedText;

//     int letters = 0;

//     for (int i = 0, n = strlen(text); i < n; i = i + 1)
//     {
//         if (text[i] >= 'a' && text[i] <= 'z')
//         {
//             letters++;
//         }else if (text[i] >= 'A' && text[i] <= 'Z'){
//             letters++;
//         }
//     }
//     // preparedText = toupper(text);
//     return letters;
// }

// int count_words(string text)
// {
//     int words = 0;

//     for(int i = 0, n = strlen(text); i < n; i++)
//     {
//         if(text[i] == ' ') {
//             words++;
//         }
//     }
//     return words +1;
// }

// int count_sentences(string text)
// {
//     int sentences = 0;

//     for(int i = 0, n = strlen(text); i < n; i++)
//     {
//         if(text[i] == '.' || text[i] == '!' || text[i] == '?') {
//             sentences++;
//         }
//     }
//     return sentences;
// }
