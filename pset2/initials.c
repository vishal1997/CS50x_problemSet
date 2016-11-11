#include<stdio.h>
#include<ctype.h>
#include<cs50.h>
#include<string.h>
int main()
{
    string s=GetString();
    int l=strlen(s);
    for(int i=0;i<l;i++)
    {
        if(i==0)
        {
            printf("%c",toupper(s[i]));
        }
        else if(s[i]==' ')
        {
            printf("%c",toupper(s[i+1]));
        }
    }
    printf("\n");
}