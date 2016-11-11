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
    // TODO: if the user didn't pass the argument or the arguments are more then 3 in cammand line then print Usage: genrate n [s].
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // TODO: Convert the character representation of number to integer form.
    int n = atoi(argv[1]);

    // TODO: If the user gives two argument in the cammand line, srand48 will be called using the seed 'argv[2]' as an argument.
    
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    //if the user give only one argument in the cammand line then srand48 will be called without any argument.
    else
    {
        srand48((long int) time(NULL));
    }

    // TODO: Prints the random numbers less then the given range.
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}