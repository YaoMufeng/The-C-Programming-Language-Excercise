#include<stdio.h>

#define IN 1
#define OUT 0
/*

comment type 1
*/


//comment type 2

//comment type 3

/**/

/* /////sdf



sdfsd
q

weqweasd//*/


int main()
{
int c,nl,nw,nc,state;

state=OUT;
nl=nw=nc=0;

while((c=getchar())!=EOF)
{
++nc;

if(c=='\n')
++nl;

if(c==' '||c=='\n'||c=='\t')
state=OUT;
else if(state==OUT)
{
state=IN;
++nw;
}
}

printf("%d %d %d\n",nl,nw,nc);

return 0;
}
//sfsdfsdfweqrqrq/* sdf */adasdasdasd//
/*fsdfs
sdfsdfsd
*?
/