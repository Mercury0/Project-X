/**
 * resize.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Resizes a BMP file by a factor of n.
 */
       
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#include "bmp.h"

// function prototypes
bool isNumber (char* arr);

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4 || !isNumber(argv[1]))
    {
        printf("Usage: ./resize <n> infile outfile.\n");
        printf("       n must be a positive integer.\n");
        return 1;
    }

    // declare variables
    int n = atoi(argv[1]); // initialize and convert n input to integer
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0 
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    // keep track of original dimensions 
    int initialWidth = bi.biWidth;
    int initialHeight = bi.biHeight;
    
    // update dimensions by factor of n
    bi.biWidth *= n;
    bi.biHeight *= n;
    
      // determine padding for scanlines
    int initialPadding = (4 - (initialWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int newPadding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // update size attributes 
    bi.biSizeImage = (bi.biWidth * sizeof(RGBTRIPLE) + newPadding) * abs(bi.biHeight);
    bf.bfSize = bf.bfOffBits + bi.biSizeImage;
   
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0; i < abs(initialHeight); i++)
    {
        // iterate vertically
            for (int j = 0; j < n; j++)
            {
                long shift = initialWidth * sizeof(RGBTRIPLE) + initialPadding;
                fseek(inptr, bf.bfOffBits + (shift * i), SEEK_SET);
                
                // iterate horizontally
                for (int k = 0; k < initialWidth; k++)
                {
                    // temporary storage
                    RGBTRIPLE triple;
                
                    // read RGB triple from infile
                    fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                    
                    // writes RGB triple n times to outfile
                    for (int l = 0; l < n; l++)
                        fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }

        // add padding to outfile
        for (int m = 0; m < newPadding; m++)
            fputc(0x00, outptr);
            }
    }
    
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // exit program
    return 0;
}

bool isNumber(char* arr)
{
    for (int i = 0, n = strlen(arr); i < n; i++)
    {
        if(isalpha(arr[i])) // false if input contains alphabetic characters, otherwise true
            return false;
    }
    return true;
}