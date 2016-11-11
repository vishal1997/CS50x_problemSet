#include<stdio.h>
#include<cs50.h>
int main()
{
    int height,i,j,k;
    do
    {
    printf("Enter the height between 0 to 23 ");
    height=GetInt();
    }
    while(height<0||height>23);
    for(i=height;i>0;i--)
    {
        for(j=1;j<i;j++)
        {
            printf(" ");
        }
        for(k=j;k<=height+1;k++)
        {
        printf("#");
        }
        printf("\n");
    }
}