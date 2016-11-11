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
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int first=0;
    int last=n-1;
    do
    {
        int middle=(first+last)/2;
        if(value==values[middle])
        {
             return true;
         }
         else if(value<values[middle])
         {
             last=middle-1;
         }
         else
             first=middle+1;
    }
    while(first<=last);
 return false;
}


/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    for (int front = 0; front < n-1; front++)
    {   
    for (int i = front; i < n-front-1; i++)
    {
        if (values[i] < values[i+1])
        {
            int tmp = values[front];
            values[front] = values[i+1];
            values[i+1] = tmp;
        }
    }
    }
    // TODO: implement an O(n^2) sorting algorithm
    return;
}

