#include <stdio.h>

int search(int x,int n, int arr[])
{
    int i;
    for(i=0;i<n;i++)
        if(x == arr[i])
            return 1;
    return 0;
}

int main()
{
    int n,m,ref[n],page[m],front=0,i,j;
    printf("Enter number of ref string values: ");
    scanf("%d",&n);
    printf("Enter number of page values: ");
    scanf("%d",&m);
    printf("Enter ref string\n");
    for(i=0;i<n;i++)
        scanf("%d",&ref[i]);
    for(i=0;i<m;i++)
        page[i] = ref[i];
    for(i=m;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(search(ref[i],m,page) == 0)
            {
                page[front] = ref[i];
                front++;
                if(front > m-1)
                    front = 0;
            }
        }
    }
    printf("Final Frame\n");
    for(i=0;i<m;i++)
        printf("%d\t",page[i]);
    return 0;
}