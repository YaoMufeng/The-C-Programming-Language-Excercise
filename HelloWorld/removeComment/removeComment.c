#include<stdio.h>

#define MAXLENGTH 1000

int main()
{

    FILE *fp,*fpOut;

    char filename[MAXLENGTH]="WordCount.c";
    char fileOutName[MAXLENGTH]="WordCount_copy.c";

    fp=fopen(filename,"r");
    fpOut=fopen(fileOutName,"w");

    removeComment(fp,fpOut);

    StrCat(filename,fileOutName);
    printf("%s\n",filename);

    fclose(fp);
    fclose(fpOut);
    return 0;
}


//a b c d e 0
//0 1 2 3 4 5



void StrCat(char str1[],char str2[])
{
    int i=0;

    while((str1[i])!='\0')
    i++;

    int j=0;
    while((str1[i++]=str2[j++])!='\0')
    ;
}

void removeComment(FILE *fp,FILE *fpOut)
{
    char c;

    const int noComment=0;
    const int lineComment=1;
    const int blockComment=2;

    int commentStatus=noComment;

    while((c=fgetc(fp))!=EOF)
    {

        if(commentStatus==lineComment)
        {
            if(c=='\n')
            {
                commentStatus=noComment;
            }
        }
        else if(commentStatus==blockComment)
        {
            if(c=='*')
            {
                c=fgetc(fp);
                if(c==EOF)
                {
                    return;
                }
                else if(c=='/')
                {
                    commentStatus=noComment;
                }                    
            }
        }
        else if (commentStatus==noComment)
        {
            if(c!='/')
            {
                fputc(c,fpOut);
            }
            else
            {
                c=fgetc(fp);
                if(c==EOF)
                {
                    return;
                }

                if(c=='/')
                {
                    commentStatus=lineComment;
                }
                else if(c=='*')
                {
                    commentStatus=blockComment;
                }
                else
                {
                    fputc(c,fpOut);
                }

            }
            
        }



    }
}