#include <stdio.h>

int max(int n,int arr[])
{
    int i,mIdx = 0;
    for(i=1;i<n;i++)
        if(arr[i] > arr[mIdx])
            mIdx = i;
    return mIdx;
}

int main()
{
    int n,m,i,j,b[m],b1[m],p[n],alloc[n];
    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter number of blocks: ");
    scanf("%d",&m);
    
    printf("Enter process array\n");
    for(i=0;i<n;i++)
        scanf("%d",&p[i]);
    printf("Enter block array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
        b1[i] = b[i];
        alloc[i] = -1;
    }
    for(i=0;i<n;i++)
    {
        int mIdx = max(n,b1);
        if(p[i] <= b1[mIdx])
        {
            alloc[i] = mIdx;
            b1[mIdx] -= p[i];
        }
    }
    printf("P\tB\n");
    for(i=0;i<n;i++)
        printf("%d\t%d\n",p[i],alloc[i]);
    return 0;
}