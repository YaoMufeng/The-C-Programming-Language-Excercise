#include<stdio.h>
#include<math.h>

unsigned int setbits(int x,int p,int n,int y);
unsigned int invert(int x,int p,int n);
void showBits(int digit);

int main()
{

    //unsigned int setbits1=setbits(0,10,3,253);
    unsigned int inverts1=invert(0,10,3);

    unsigned int test1=inverts1;
    showBits(test1);

    return 0;
}


unsigned int setbits(int x,int p,int n,int y)
{
    int x2=x;


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