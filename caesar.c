#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


bool is_valid_key(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isdigit(key[i]))
        {
            return false;
        }
    }
    return true;
}

int main(int argc, string argv[])
{

    if (argc != 2 || !is_valid_key(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


    int key = atoi(argv[1]);


    string plaintext = get_string("Plaintext: ");


    printf("Ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];

        if (isalpha(c))
        {
            char offset = isupper(c) ? 'A' : 'a';
            printf("%c", (c - offset + key) % 26 + offset);
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
    return 0;
}

