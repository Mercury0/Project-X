/*
================================================================================
Name    : vigenere.c
Author  : Mark Fox
Version : Problem Set 2, CS50x, Harvard University
Description : Encrypts a message with a keyword using Vigenere's cipher.
================================================================================
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2) //validates # of command-line arguments
    {
        printf("Format:  ./vigenere <keyword>\n");
        return 1;
    }
    
    string k = argv[1];
    int keyL = strlen(k);
    for (int i = 0; i < keyL; i++)
    {
        if (!isalpha(k[i])) //validates keyword requirements
        {
            printf("Keyword must contain alphabetic characters only. \n");
            return 1;
        }
    }
    
    printf("Please type a message to encrypt: \n");
    string p = GetString(); /* obtain plaintext */
  
    for (int i = 0, j = 0, n = strlen(p); i < n; i++)
    {
        char Z = p[i];
        int kLoop = k[(j++) % keyL]; /* Keyword iteration is confined to it's length,  
                                        allowing it to repeat cyclically until all letters 
                                        in the plaintext have been encrypted */
        
        if (isalpha(Z)) /* process alphabetic characters only from plaintext */
        {
            if (islower(Z)) /* ruleset for lowercase letters */
            {
                /* converts letter from ASCII to 0-indexed alphabetic position by
                subtracting 'a' then cycles through key values for encryption.
                The output expression is then re-converted to ASCII for final
                printout */
                
                char X = ((Z - 'a') + (kLoop)) % 26 + 'a';
                printf("%c", X);
            }
                else if (isupper(Z)) /* ruleset for uppercase letters */
                 {
                     /* same conversion parameters as above except for 
                     uppercase characters */
                    char Y = ((Z - 'A') + (kLoop)) % 26 + 'A';
                    printf("%c", Y);
                 }
        }
        else 
        {
            /* prints out any non-alphabetic characters from plaintext unchanged */
            printf("%c", Z);
        }
    }
    printf("\n");
    return 0;
}