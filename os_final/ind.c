#include <stdio.h>

int n,indBlock,files[50],indexBlock[50];

void recurse1()
{
    int i;
    printf("Enter index block: ");
    scanf("%d",&indBlock);
    files[indblock] = 0;
    for(i=0;i<n;i++)
    {
        if(files[i] != 0)
        {
            printf("Enter number blocks to be allocated in index %d: ",indBlock);
            scanf("%d",&n);
        }
        else
        {
            printf("Files already allocated\n");
            recurse1();
        }
    }
    recurse2();
}

void recurse2()
{
    int i;
    printf("Enter values to be allocated in index %d\n",indBlock);
    for(i=0;i<n;i++)
    {
        scanf("%d",&indexBlock[i]);
        files[indexBlock[i]] = 0;
    }
    printf("File Allocated\n");
}

int main()
{
    int i;
    for(i=0;i<n;i++)
        files[i] = -1;
    recurse1();
    return 0;
}