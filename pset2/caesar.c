#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
int main(int argc, char* argv[])
{
    string s;
    char c[100];
    if(argc!=2)
    {
        printf("Invalid input");
        return 1;
    }
    
    else
    {
        int k=atoi(argv[1]);
        int position;
        s=GetString();
        int length=strlen(s);
        for(int i=0;i<length;i++)
        {
            if(islower(s[i]))
            {
                position=(int)s[i]-97;
                c[i]=(position+k)%26;
                c[i]=(int)c[i]+97;
                printf("%c",c[i]);
            }
            else if(isupper(s[i]))
            {
                position=(int)s[i]-65;
                c[i]=(position+k)%26;
                c[i]=(int)c[i]+65;
                printf("%c",c[i]);
            }
            else if(isdigit(s[i]))
            {
                s[i]=(int)s[i]-48;
                printf("%d",(int)s[i]);
            }
            else
            {
                printf("%c",s[i]);
            }
        }
    }
    printf("\n");
    return 0;
}