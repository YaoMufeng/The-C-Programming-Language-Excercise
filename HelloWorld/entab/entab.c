#include<stdio.h>
#include<malloc.h>
#define MAXLENGTH 1000

char* entab(char src[]);
char* detab(char src[]);
int getLine(char s[],int lim);


int main()
{
    char src[MAXLENGTH];
    getLine(src,MAXLENGTH);
    char *detabed=detab(src);

    char *entabed=entab(src);

    printf("detabed=%s \n",detabed);
    printf("entabed=%s \n",entabed);

    return 0;
}







char* detab(char src[])
{
    int len=strlen(src);

    //char *dst=(char*)malloc(len*sizeof(char));
    int tabLength=4;

    int tabCount=0;

    for (int i=0;i<len;i++)
    {
        if (src[i]=='\t')
        {
            tabCount++;
        }
    }

    int space=len+tabCount*3;
    char *dst=(char*)malloc(len*sizeof(char));

    int pos=0;
    for(int i=0;i<len;i++)
    {

        if (src[i]=='\t')
        {
            for(int j=0;j<tabLength;j++)
            {
                dst[pos]=' ';
                pos++;
            }
        }
        else
        {
            dst[pos]=src[i];
            pos++;
        }


    }
    return dst;
}

char *entab(char src[])
{
    int len=strlen(src);

    char* dst=(char*)malloc(len*sizeof(char));

    int pos=0;

    int preIsSpace=0;

    for(int i=0;i<len;i++)
    {
        //printf("i= %d preIsSpace= %d\n",i,preIsSpace);
        if(src[i]==' ')
        {
            preIsSpace=1;
        }
        else
        {
            if(preIsSpace==1)
            {
                dst[pos]='\t';
                pos++;
                preIsSpace=0;
            }
            dst[pos]=src[i];
            pos++;
        }

    }
    return dst;
}

int getLine(char s[],int lim)
{
    int c,i;

    for(i=0;i<lim-1&&((c=getchar())!=EOF)&&c!='\n';++i)
    {
        s[i]=c;
    }
    if(c=='\n')
    {
        s[i]=c;
        ++i;
    }
    s[i]='\0';
    return i;
}