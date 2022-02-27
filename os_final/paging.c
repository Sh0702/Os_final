#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i,n,m,pages,startAdd;
    printf("Enter number of frames: ");
    scanf("%d",&n);
    printf("Enter frame size: ");
    scanf("%d",&m);
    printf("Enter number of pages: ");
    scanf("%d",&pages);
    printf("Enter starting address: ");
    scanf("%d",&startAdd);
    int f[n],page[n],pagetable[n];
    f[0] = startAdd;
    page[0] = -1;
    for(i=1;i<n;i++)
    {
        f[i] = f[i-1] + m;
        page[i] = -1; 
    }

    int count = 0;

    srand(time(NULL));
    while(count < pages)
    {
        int x = rand() % n;
        if(page[x] == -1)
        {
            page[x] = count;
            pagetable[count] = x;
            count++;
        }
    }
    printf("F\tP\tPA\n");
    for(i=0;i<n;i++)
        printf("%d\t%d\t%d\n",i,page[i],f[i]);
    int pg,offset;
    printf("Enter page number: ");
    scanf("%d",&pg);
    printf("Enter offset: ");
    scanf("%d",&offset);
    printf("Physical address: %d",(f[pagetable[pg]] + offset));
    return 0;
}