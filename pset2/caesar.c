#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{

    //Checks to see if the argument entered is a valid length//
    if (argc == 2)
    {

        //Checks to see if the key entered is a valid type - integer//
        int x = strlen(argv[1]);
        for (int i = 0; i < x; i++)
        {
            if (isdigit(argv[1][i]))
            {
                int key = atoi(argv[1]);
            }
            else
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        int key = atoi(argv[1]);

        //Gets input - plaintext = original message//
        string plaintext = get_string("plaintext:  ");
        int y = strlen(plaintext);

        //Uses the key to cipher the original message//
        for (int j = 0; j < y; j++)
        {
            if (isalpha(plaintext[j]))
            {
                if ((plaintext[j] + key > 90 && plaintext[j] + key < 97) || plaintext[j] + key > 122)
                {
                    if (plaintext[j] > 65 && plaintext[j] < 91)
                    {
                        int m = ((plaintext[j] + key) - 91)/26;
                        plaintext[j] = (plaintext[j] + key) - (26 * (m+1));
                    }
                    else if (plaintext[j] > 96)
                    {
                        int h = ((plaintext[j] + key) - 123)/26;
                        plaintext[j] = (plaintext[j] + key) - (26 * (h+1));
                    }
                }
                else
                {
                    plaintext[j] = plaintext[j] + key;
                }
            }
            else if (isspace(plaintext[j]) || ispunct(plaintext[j]))
            {
                plaintext[j] = plaintext[j];
            }
        }
        printf("ciphertext: %s\n", plaintext);
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
