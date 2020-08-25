#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define ENG 26
//isalpha isupper islower ASCII strlen(text)


int main(int argc, string argv[])
{
    char c = 0;
    
    if (argc == 2)
    {   
        for (int i = 0; argv[1][i]; ++i)
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int k = atoi(argv[1]);
    string s = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isalpha(s[i]))
        {
            if (isupper(s[i]))
            {
                c = (((s[i] - 65) + k) % 26) + 65;
                printf("%c", c);
            }
            else if (islower(s[i]))
            {
                c = (((s[i] - 97) + k) % 26) + 97;
                printf("%c", c);
            }
        }
        else
            printf("%c", s[i]);
        }
        printf("\n");

}