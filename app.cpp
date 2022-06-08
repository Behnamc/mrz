#include <stdio.h>
int f (int , int );

int main()
{
    int  l , r , x , k , d , T = 0 ;
    scanf("%d%d%d",&l,&r,&d);
    for (int i = l ; i <= r ; i++)
        T+=f(i,d);
        //printf("%d\n",f(i,d));
        printf("%d",T);
}

int f (int x , int k )
{
    int a[100]={0} ;
    a[0]=x;
    if (x%2==0)
        a[1]=x/2;
    else
        a[1]=x+k;

    for (int i = 2 ; i<=100 ; i++)
    {
        if (a[i-1]%2==0)
            a[i]=a[i-1]/2;
        else
            a[i]=a[i-1]+k;
    }

    for (int i = 0 ; i<=100 ; i++)
        if (a[i]<=k)
            return i ;
}