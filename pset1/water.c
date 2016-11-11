#include <stdio.h>
#include <cs50.h>
int main()
{
    printf("Enter the lenght of your shower in minutes");
    int length, bottel;
    length=GetInt();
    bottel=length*12;
    printf("Minutes=%d\n",length);
    printf("Bottel=%d\n",bottel);
}