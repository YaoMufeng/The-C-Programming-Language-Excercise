#include<stdio.h>
#include<ctype.h>
#include<malloc.h>
#include<string.h>
#include<math.h>
#include"../BitWise/BitWise.h"

#define MAXLENGTH 1000

int atoi(char string[]);
char* reverse(char src[]);
char *expand(char src[]);
char *itoa(int x);
char *Itoa(int x,int width);
char *itob(int x,int b);
void showBits(int digit);



int main()
{
    int num1=256;
    int num2=15;
    int num3=7519813;
    int num4=-2147483648;

    printf("%s\n",Itoa(num1,10));
    printf("%s\n",Itoa(num2,10));
    printf("%s\n",Itoa(num3,10));
    printf("%s\n",Itoa(num4,10));
    return 0;
}

char *itob(int x,int b)
{
    char *dst=(char*)malloc(sizeof(char)*(MAXLENGTH+1));
    int sign=0;
    int pos=0;
    char table[37]="0123456789abcdefghijklmnopqrstuvwxyz";
    
    if(x<0){
        sign=-1;
    }
    else{
        sign=1;
    }

    do{
        dst[pos]=table[abs(x%b)];
        pos++;
        x=x/b;
    }while(x!=0);

    if(sign<0)
    {
        dst[pos]='-';
        pos++;
    }
    dst[pos]='\0';
    return reverse(dst);
}

char *itoa(int x)
{
    char *dst=(char*)malloc(sizeof(char)*(MAXLENGTH+1));
    int sign=0;
    int pos=0;


    if(x<0){
        sign=-1;
    }
    else{
        sign=1;
    }

    do{
        dst[pos]=abs(x%10)+'0';
        pos++;
        x=x/10;
    }while(x!=0);

    if(sign<0)
    {
        dst[pos]='-';
        pos++;
    }
    dst[pos]='\0';
    return reverse(dst);
}

char *Itoa(int x,int width)
{
    char *dst=(char*)malloc(sizeof(char)*(MAXLENGTH+1));
    int sign=0;
    int pos=0;


    if(x<0){
        sign=-1;
    }
    else{
        sign=1;
    }

    do{
        dst[pos]=abs(x%10)+'0';
        pos++;
        x=x/10;
    }while(x!=0);

    if(sign<0)
    {
        dst[pos]='-';
        pos++;
    }
    dst[pos]='\0';

    if(pos>=width)
    {

        return reverse(dst);
    }
    else
    {
        char *dst2=(char*)malloc(sizeof(char)*(MAXLENGTH+1));

        int pos2=0;
        for(int i=0;i<width-pos;i++)
        {
            dst2[i]=' ';
            pos2++;
        }
        int dstlen=strlen(dst);
        for(int i=0;i<dstlen;i++)
        {
            dst2[pos2]=dst[dstlen-i-1];
            pos2++;
        }
        dst2[pos2]='\0';
        free(dst);
        return dst2;

    }

}

int atoi(char string[])
{
    int num=0;
    int i;
    for(i=0;isspace(string[i]);i++)
        ;
    int sign=1;

    sign=string[i]=='-'?-1:1;
    if (string[i]=='-'||string[i]=='+')
    {
        i++;
    }

    for(;isdigit(string[i]);i++)
    {
        num=num*10+(string[i]-'0');
        printf("char=%c num=%d \n",string[i],num);
    }
    return num*sign;
}


char* reverse(char src[])
{
    int len=strlen(src);

    char *dst=(char*)malloc(sizeof(char)*(len+1));
    char temp;
    for(int i=0;i<len;i++)
    {
        dst[i]=src[len-i-1];
    }
    dst[len]='\0';

    return dst;
}


char *expand(char src[])
{
    const int NoDigitAlpha=0;
    const int IsDigit=1;
    const int IsAlpha=2;

    int status=NoDigitAlpha;

    char *dst=(char*)malloc(sizeof(char)*MAXLENGTH);

    int posSrc=0;
    int posDst=0;

    int waitChar=0;

    char buff=0;

    int step=0;

    while(src[posSrc]!='\0')
    {
        if(isdigit(src[posSrc]))
        {
            status=IsDigit;
            if(waitChar)
            {
                if(isdigit(buff))//前一个buff字符也是数字
                {
                    step=src[posSrc]-buff>0?1:-1;
                    for(char a=buff+step;a!=src[posSrc];a+=step)
                    {
                        dst[posDst]=a;
                        posDst++;
                        
                    }
                    dst[posDst]=src[posSrc];
                    posDst++;
                    buff=src[posSrc];
                    waitChar=0;
                }
            }
            else
            {
                buff=src[posSrc];
                dst[posDst]=src[posSrc];

                posDst++;
            }
        }
        else if (isalpha(src[posSrc]))
        {
            status=IsAlpha;
            if(waitChar)
            {
                if(isalpha(buff))//前一个buff字符也是字母
                {
                    step=src[posSrc]-buff>0?1:-1;
                    for(char a=buff+step;a!=src[posSrc];a+=step)
                    {
                        dst[posDst]=a;
                        posDst++;
                    }
                    dst[posDst]=src[posSrc];
                    buff=src[posSrc];
                    posDst++;
                    waitChar=0;
                }

            }
            else
            {
                buff=src[posSrc];

                dst[posDst]=src[posSrc];
                posDst++;
            }
        }
        else if (src[posSrc]=='-')
        {
            if (status==IsDigit)
            {
                waitChar=1;
            }
            else if(status==IsAlpha)
            {
                waitChar=1;
            }
        }
        else
        {
            dst[posDst]=src[posSrc];
            posDst++;
            status=NoDigitAlpha;
            waitChar=0;
        }
        posSrc++;
    }
    dst[posDst]='\0';
    return dst;
}


