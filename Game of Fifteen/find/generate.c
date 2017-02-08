/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    /* TODO: validates command-line arguments. If not 2 or 3, re-prompts
     user to try again */
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    /* TODO: converts string input to integer and stores it to variable n
    so it can be used in mathematical operations */
    int n = atoi(argv[1]);

    /* TODO: if the argument count is 3, seed the pseudorandom number(s)
    generated with the seed provided, otherwise seed the pseudorandom 
    number(s) with the current time (since it is a value that always 
    changes). */
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    /* TODO: prints each pseudorandom number generated on its
    own line using drand48(), which prints pseudorandom numbers in 
    floating-point format over the interval [0.0, 1.0], then 
    multiplies them by the constant 65536 to convert them to an int. */
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}