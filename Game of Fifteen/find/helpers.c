/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false. Uses
 * binary search method.
 **/
bool search(int value, int values[], int n)
{
    if (n <= 0)
    {
        return false;
    }
    for (int i = 0; i < n; i++)
    
    first = 0;
    last = n - 1;
    middle = (first + last)/2;
    
    while (first <= last)
    {
        if (values[middle] < value)
        first = middle + 1;
        
        else if (values[middle] == value)
        {
            printf("%d found at location %d.\n", value, middle +1);
            break;
        }
        else
            last = middle - 1;
            middle = (first + last)/2;
    }
    if (first > last)
    {
        printf("Not found! %d is not present in the list.\n", value);
    }
    return 0;
}
       
/**
 * Sorts array of n values using bubble sort method.
 */
void sort(int values[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (values[j+1] < values[j])
            {
                temp = values[j];
                values[j] = values[j+1];
                values[j+1] = temp;
            }
        }
    }
}
