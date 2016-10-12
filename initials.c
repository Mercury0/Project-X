#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
   string s = GetString();

     //capitalizes and prints first character in string if alphabetic
            if (isalpha(s[0]))
            {
                printf("%c", toupper(s[0]));
            }
    
     //loop to locate, capitalize, and print characters preceded by a space
        for (int i = 0, n = strlen(s); i < n; i++)
        {
             if (s[i] == ' ' && s[i+1] != ' ')
            {
                printf("%c", toupper(s[i+1]));
            }
           
        }
        
        //print new line
        printf("\n");
}
