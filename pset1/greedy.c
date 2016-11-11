#include<stdio.h>
#include<cs50.h>
#include<math.h>
int main()
{
    int quar=25,dim=10,nic=5,pen=1,i=0;
    float dol,cent=0;
    printf("How much change is owed");
    do
    {
    dol=GetFloat();
    }
    while(dol<0);
    cent=100*dol;
    cent=round(cent);
    while(cent>=quar)
    {
        cent=cent-quar;
        i++;
    }
    while(cent>=dim)
    {
        cent=cent-dim;
        i++;
    }
    while(cent>=nic)
    {
        cent=cent-nic;
        i++;
    }
    while(cent>=pen)
    {
        cent=cent-pen;
        i++;
    }
    printf("No. of coins= %d",i);
}