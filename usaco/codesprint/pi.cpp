#include<stdio.h>
main()
{double n,t,i,a,j,m,k;scanf("%lf",&t);for(i=0;i<t;i++){scanf("%lf",&n);a=0;m=1;for(j=1;j<2*n+1;j+=2){a+=m/j;m*=-1;};printf("%0.15lf\n",a);}}
