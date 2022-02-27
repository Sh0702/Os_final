#include <stdio.h>

int min(int n,int arr[])
{
    int mIdx=0,i;
    for(i=1;i<n;i++)
        if(arr[i] < arr[mIdx])
            mIdx = i;
    return mIdx;
}

int search(int n,int arr[],int x)
{
    int i;
    for(i=0;i<n;i++)
        if(arr[i] == x)
            return 1;
    return 0;
}

int main()
{
    int n,m,i,j,k,ref[n],page[m],count[m];
    printf("Enter number of values in reference string: ");
    scanf("%d",&n);
    printf("Enter number of page values: ");
    scanf("%d",&m);
    for(i=0;i<m;i++)
        count[i] = 0;
    if(n < m)
    {
        printf("Number of pages should be lesser than number of values in reference string\n\n");
        printf("Enter number of values in reference string: ");
        scanf("%d",&n);
        printf("Enter number of page values: ");
        scanf("%d",&m);
    }
    printf("\n\nEnter reference string\n");
    for(i=0;i<n;i++)
        scanf("%d",&ref[i]);
    for(i=0;i<m;i++)
        page[i] = ref[i];
    for(i=m;i<n;i++)
    {
        if(search(n,page,ref[i]) == 0)
        {
            for(j=i+1;j<n;j++)
                for(k=0;k<m;k++)
                    if(ref[j] == page[k])
                        count[k]++;
            int mIdx = min(m,count);
            page[mIdx] = ref[i]; 
        }
    }
    printf("Final Frame\n");
    for(i=0;i<m;i++)
        printf("%d\t",page[i]);
    return 0;
}