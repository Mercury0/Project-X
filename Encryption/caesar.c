/*
================================================================================
Name    : caesar.c
Author  : Mark Fox
Version : Problem Set 2, CS50x, Harvard University
Description : Encrypts a message using Caesar's cipher.
================================================================================
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Format:  ./caesar <key value>\n");
        return 1;
    }
    else 
    {
        printf("Please type a message you would like to encrypt: \n");
        string s = GetString(); //obtain plaintext
        
        //transform caesar k-value from string to int
        int k = atoi(argv[1]);
        
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            char c = s[i];
            
            if (isalpha(c)) //checks if character is alphabetic
            {
                 if (islower(c)) //handles lowercase characters
                {
                    /* convert index value from ASCII to alphabetic position by
                    subtracting 'a', then apply mod 26 */
                    char a = ((c - 'a' + k) % 26);
                    /* re-convert to ASCII for proper printout by adding 'a' */
                    char b = (a + 'a');
                    printf("%c", tolower(b));
                }
                else if (isupper(c)) //handles uppercase characters
                {
                    /* same as above but with 'A' for uppercase bounds rather than 'a' */
                    char a = ((c - 'A' + k) % 26);
                    char b = (a + 'A');
                    printf("%c", toupper(b));
                }
            }
            else
            {
                printf("%c", c); //prints character unchanged if non-alphabetic
            }
        }
        printf("\n");
        return 0;
    }
}