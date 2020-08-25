#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <string.h>



int main(void)
{
    string s = get_string("Text: ");
    int i = 0, len = 0, CtWord = 1, Sentence = 0, Index = 0;


    while (s[i++])
        if ((s[i - 1] >= 'A' && s[i - 1] <= 'Z') || (s[i - 1] >= 'a' && s[i - 1] <= 'z'))
            len++;

    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
         CtWord++;
    }

    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        Sentence++;
    }

    float L = (len * 100 / (float)CtWord);
    float S = (Sentence * 100 / (float)CtWord);
    Index = round(0.0588 * L - 0.296 * S - 15.8);
    if (Index > 16)
    {
        printf("Grade 16+\n");
    }
    if (Index < 1)
    {
        printf("Before Grade 1\n");
    }
    if ((Index > 1) && (Index < 16))
    {
        printf("Grade %d\n", Index);
    }
    return 0;
}

