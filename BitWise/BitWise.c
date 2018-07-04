#include<stdio.h>
#include<math.h>
#define MAXLENGTH 1000

#include"BitWise.h"


/*int main()
{

    //unsigned int setbits1=setbits(0,10,3,253);
    //unsigned int inverts1=invert(5,2,3);

    //unsigned int test1=inverts1;
    //showBits(test1);
    int digit=12346541;
    showBits(digit);

    printf("bitcount=%d\n",bitcount(digit));
    printf("fastBitCount=%d\n",fastBitCount(digit));

    int n=2;
    printf("you have %d item%s\n",n,n>1?"s":"");

    char string[MAXLENGTH]="aBcDeFghijK";
    printf("%s\n",string);
    lower(string);
    printf("%s\n",string);

    return 0;
}*/

void lower(char src[])
{
    int i=0;
    int dis='A'-'a';
    while(src[i]!='\0')
    {
        src[i]=(src[i]>='A'&&src[i]<='Z')?src[i]-dis:src[i];
        i++;
    }
}

int bitcount(unsigned int x)
{
    int b;
    for(b=0;x!=0;x>>=1)
    {
        if(x&01)
        b++;
    }
    return b;
}
int fastBitCount(unsigned int x)
{
    int count=0;
    while(x!=0)
    {
        x&=(x-1);
        count++;
    }
    return count;
}

unsigned int setbits(int x,int p,int n,int y)
{
    unsigned int x2=(unsigned int)x;


    int intSize=sizeof(int)*8;
    unsigned int inverseZero=~0;
    unsigned int mask=(inverseZero<<(p-n+1))&(inverseZero>>(intSize-p-1));

    mask=~mask;
    showBits(mask);

    x2=x2&mask;
    showBits(x2);

    unsigned int maskY=inverseZero>>(intSize-n);
    showBits(y);
    showBits(maskY);

    unsigned int y2=(maskY&y)<<(p-n+1);
    showBits(y2);

    return (unsigned int)(x2+y2);
}

unsigned int invert(int x,int p,int n)
{
    int intSize=sizeof(int)*8;

    unsigned int inverseZero=~0;
    unsigned int mask=(inverseZero<<(p-n+1))&(inverseZero>>(intSize-p-1));
    

    return (~x)&mask+(x&(~mask));
}

void showBits(int digit)
{
    int intSize=sizeof(int)*8;

    int one=1;
    int mask=0;
    int maskResult=0;
    for(int i=intSize-1;i>=0;i--)
    {
        mask=one<<i;
        maskResult=(mask&digit)/mask;
        printf("%d ",maskResult);
    }
    printf("\n");
}