#include<stdio.h>
#include<string.h>
#include<cs50.h>
#include<ctype.h>
int main(int argc, char* argv[])
{
    if(argc!=2) 
    {
        printf("Invalid Input");
        return 1;
    }
    int key_len=strlen(argv[1]);
    for(int i=0;i<key_len;i++)
    {
        if(isdigit(argv[1][i]))
        {
            printf("Invalid input");
            return 1;
        }
    }
        char c[100];
        int position, keyposition;
        string s=GetString();
        int len=strlen(s);
        int j=0;
        for(int i=0;i<len;i++)
        {
            if(j==key_len)
            {
                j=0;
            }
            if(isalpha(s[i]))
            {
                
                if(islower(argv[1][j]))
                { 
                    keyposition=(int)argv[1][j]-97;
                    if(islower(s[i]))
                    {
                        position=(int)s[i]-97;
                        c[i]=(position+keyposition)%26;
                        c[i]=c[i]+97;
                        printf("%c",c[i]);
                    }
                    else if(isupper(s[i]))
                    {
                        position=(int)s[i]-65;
                        c[i]=(position+keyposition)%26;
                        c[i]=c[i]+65;
                        printf("%c",c[i]);
                    }
                    j++;
                }
                else if(isupper(argv[1][j]))
                {
                    keyposition=(int)argv[1][j]-65;
                    if(islower(s[i]))
                    {
                        position=(int)s[i]-97;
                        c[i]=(position+keyposition)%26;
                        c[i]=c[i]+97;
                        printf("%c",c[i]);
                    }
                    else if(isupper(s[i]))
                    {
                        position=(int)s[i]-65;
                        c[i]=(position+keyposition)%26;
                        c[i]=c[i]+65;
                        printf("%c",c[i]);
                    }
                    j++;
                }
                else
                    printf("%c",s[i]);
                }
            else 
                printf("%c",s[i]);
        }
        printf("\n");
        return 0;
    
}