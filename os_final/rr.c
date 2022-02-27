#include <stdio.h>

int main()
{
    int n,i,remain,count,tq,at[n],bt[n],rt[n],time,flag=0;
    float wt=0,tat=0,awt,att;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    remain = n;
    printf("Enter time quantum: ");
    scanf("%d",&tq);
    printf("Enter Arrival and Burst Time\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&at[i],&bt[i]);
        rt[i] = bt[i];
    }
    for(time = 0,count = 0;remain != 0;)
    {
        if(rt[count] <= tq && rt[count] > 0)
        {
            time += rt[count];
            rt[count] = 0;
            flag = 1;
        }
        else if(rt[count] > 0)
        {
            rt[count] -= tq;
            time += tq;
        }
        if((rt[count] == 0) && (flag==1))
        {
            remain--;
            wt += time - at[count] - bt[count];
            tat += time - at[count];
            flag = 0;
        }
        else if(count == n-1)
            count = 0;
        else if(at[count+1] <= time)
            count++;
        else
            count = 0;
    }
    awt = wt*1.0/n;
    att = tat*1.0/n;
    printf("Average Waiting Time = %f\nAverage Turnaround Time = %f\n",awt,att);
    return 0;
}