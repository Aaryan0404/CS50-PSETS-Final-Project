#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function declaration prototype//
int shift(char c);

int main(int argc, string argv[])
{
    // Checks the length of the command-line input//
    if (argc == 2)
    {
        // Checks if input-keyword is completely numerical//
        int x = strlen(argv[1]);
        for (int i = 0; i < x; i++)
        {
            if (isalpha(argv[1][i]))
            {
                int key = shift(argv[1][0]);
            }
            else
            {
                printf("Usage: ./vigenere keyword\n");
                return 1;
            }
        }

        // Takes in plaintext input//
        string plaintext = get_string("plaintext:  ");
        int y = strlen(plaintext);
        int key = 0;
        string keyword = argv[1];
        int l = strlen(keyword);
        int k = 0;

        // Uses keyword to create cipher of plaintext//
        for (int j = 0; j < y; j++)
        {
            if (k > l)
            {
                key = shift(argv[1][k % l]);
                k = k + 1;
            }
            else if (k == l)
            {
                key = shift(argv[1][k - l]);
                k = k + 1;
            }
            else if (k < l)
            {
                key = shift(argv[1][k]);
                k = k + 1;
            }

            if (isalpha(plaintext[j]))
            {
                if ((plaintext[j] + key > 90 && plaintext[j] + key < 97) || plaintext[j] + key > 122)
                {
                    int m = plaintext[j] + key;
                    plaintext[j] = m - 26;
                }
                else
                {
                    int r = key / 25;
                    plaintext[j] = (plaintext[j] + key) - (26 * r);
                }
            }
            else if (isspace(plaintext[j]) || ispunct(plaintext[j]))
            {
                plaintext[j] = plaintext[j];
                k = k - 1;
            }
        }
        printf("ciphertext: %s\n", plaintext);
    }
    else
    {
        printf("Usage: ./vigenere key\n");
        return 1;
    }
}

// Definition of keyword (shift) function//
int shift(char c)
{
    int key = 0;
    int x = (int) c;
    if (x > 96)
    {
        x = (int) toupper(c);
        key = x - 65;
    }
    else if (x > 64 && x < 97)
    {
        key = x - 65;
    }
    return key;
}
