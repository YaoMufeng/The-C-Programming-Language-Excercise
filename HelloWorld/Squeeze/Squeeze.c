#include<stdio.h>

#define MAXLENGTH 1000
char *SubString(char src[],int begin,int len);

int main()
{

    char str1[MAXLENGTH]="this is my word word1 word2 word3";
    char strToMatch[MAXLENGTH]="abababca";

    Squeeze(str1,strToMatch);

    return 0;
}



char* Squeeze(char str1[],char strToMatch[])
{
    int len=strlen(strToMatch);
    
    int *table=(int*)malloc(len*sizeof(int));
    memset(table,0,len*sizeof(int));

    // initialize table
    for(int subStrLen=1;subStrLen<len;subStrLen++)
    {
        char *subStr=SubString(strToMatch,0,subStrLen+1);
        for(int cursor=0;cursor<subStrLen;cursor++)
        {
            char *front=SubString(subStr,0,cursor+1);
            char *back=SubString(subStr,subStrLen-cursor,cursor+1);
            if(match(front,back))
            {
                table[subStrLen]=cursor+1;
            }

            free(front);
            free(back);
        }
    }

    int len1=strlen(str1);

    char *dst=(char*)malloc((len1+1)*sizeof(char));

    char *buff=(char*)malloc((len+1)*sizeof(char));

    int cursor=0;
    int pos=0;

    const int InString=1;
    const int NotInString=0;
    int InStringStatus=NotInString;

    for(int i=0;i<len1;i++)
    {
        if(str1[i]!=strToMatch[cursor])
        {
            strToMatch[pos]=str1[i];
            pos++;



            if(InStringStatus==InString)
            {
                
            }


            InStringStatus=NotInString;
        }
        else
        {
            buff[cursor]=str1[i];
            InStringStatus=InString;
        }
    }

    free(buff);
    free(dst);
    free(table);
}

char *SubString(char src[],int begin,int len)
{
    char *dst=(char*)malloc((len+1)*sizeof(char));
    for(int i=0;i<len;i++)
    {
        dst[i]=src[begin+i];
    }
    dst[len]='\0';

    return dst;
}

int match(char str1[],char str2[])
{
    int i=0,j=0;

    while(str1[i]!='\0')
    {
        if(str1[i]!=str2[i])
        {
            return 0;
        }
        i++;

    }
    
    if(str2[i]=='\0')
        return 1;
    else
        return 0;
}