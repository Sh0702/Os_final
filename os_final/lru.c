#include <stdio.h>

int max(int n,int arr[])
{
    int i,maxIdx = 0 ;
    for(i=1;i<n;i++)
        if(arr[i] > arr[maxIdx])
            maxIdx = i;
    return maxIdx;
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
    int no_of_frames,no_of_pages,i,j;
    printf("Enter number of frames: ");
    scanf("%d",&no_of_frames);
    printf("Enter number of pages: ");
    scanf("%d",&no_of_pages);
    int frame[no_of_frames],ref[no_of_pages],count[no_of_frames];
    for(i=0;i<no_of_frames;i++)
        count[i] = 0;
    printf("Enter reference string: ");
    for(i=0;i<10;i++)
        scanf("%d",&ref[i]);
    for(i=0;i<no_of_frames;i++)
        count[i] = 0;
    for(i=0;i<no_of_frames;i++)
    {
        frame[i] = ref[i];
        for(j=0;j<=i;j++)
            count[j]++;
    }
    for(i=no_of_frames;i<no_of_pages;i++)
    {
        if(search(no_of_frames,frame,ref[i]) == 0)
        {
            int mIdx = max(no_of_frames,count);
            frame[mIdx] = ref[i];
            for(j=0;j<no_of_frames;j++)
                count[j]++;
            count[mIdx] = 0;
        }
        else
        {
            for(j=0;j<no_of_frames;j++)
                count[j]++;
            for(j=0;j<no_of_frames;j++)
                if(frame[j] == ref[i])
                    count[j] = 0;
        }
    }
    printf("\nFinal Frame\n");
    for(i=0;i<no_of_frames;i++)
        printf("%d\t",frame[i]);
    return 0;
}