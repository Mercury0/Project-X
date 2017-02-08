/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // open memory card file
    FILE* inptr = fopen("card.raw", "r");
    
    // validates file exists and can be opened
    if (inptr == NULL)
    {
        printf("Could not open 'card.raw'.\n");
        return 1;
    }
    
    // initialize and declare null pointer to temp output file
    FILE* outptr = NULL;
    
    // jpg counter
    int jpg = 0;
    
    // perform subroutine(s) until end of file is reached
    while (!feof(inptr))
    {
         // buffer declaration
        unsigned char buffer[512];
        
        // read buffer   
        fread(&buffer, sizeof(buffer), 1, inptr);    
        
        // validate jpg hex signature (first 4-bytes)
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
        {
                 // set array so jpg file names are output as three-digit decimal numbers
                char temp[8];
                
                // name file with 3 digits
                sprintf(temp, "%03d.jpg", jpg);
                
                // open file to write to
                outptr = fopen(temp, "w");
                
                // increment jpg counter
                jpg++;
        }
        
        if (jpg > 0)
            fwrite(&buffer, sizeof(buffer), 1, outptr);
    }
        
    // close output file    
    fclose(outptr);
    
    // close input file
    fclose (inptr);
}
        
    
    
   
