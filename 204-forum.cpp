#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()  {
    double dtime=clock();
    int pr[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    int *A,i,j,p,x,ct,ct2;
    int limit,bound=1000000000;
    A=(int*)(malloc)(3000000*sizeof(int));
    A[0]=1;
    ct=1;
    for(i=0;i<25;i++)  {
        p=pr[i];
        ct2=ct;
        limit=bound/p;
        for(j=0;j<ct;j++)  {
            x=A[j];
            while(x<=limit)  x*=p,A[ct2]=x,ct2++;
        }
        ct=ct2;
    }
    printf("%d,time=%.3lf sec.\n",ct,(double) (clock()-dtime)/CLOCKS_PER_SEC);
    return 0;
}
