#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int cyphertext(string plaintext,int key);

int main(int argc, string argv[])
{
    // Check if there is only one command line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        // Check if the command line argument is a number
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
    }
     int k = atoi(argv[1]);
    //  int key = (int)k;
    //  k = (int)k;

    if(k<1 || k == 26)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    cyphertext(plaintext ,k);

    return 0;
}

int cyphertext(string plaintext,int key)
{
    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                printf("%c", ((((plaintext[i] - 'A') + key) % 26)) + 'A');
            }
            else
            {
               printf("%c", ((((plaintext[i] - 'a') + key) % 26)) + 'a');
            }
        }
        else
        {
            printf("%c", plaintext[i] );
        }
    }
         printf("\n");

    return 0;
}
