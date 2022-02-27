#include <stdio.h>

struct process
{
    int at,bt,wt,tat,p;
};

struct process a[10];

int main()
{
    int i,j,n,count=0,short_p,t;
    float total_tat=0,total_wt=0,avg_wt,avg_tat;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    int temp[n];
    printf("Enter Arrival Time, Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&a[i].at,&a[i].bt,&a[i].p);
        temp[i] = a[i].bt;
    }
    a[9].p = 10000;
    for(t=0;count!=n;t++)
        if((a[short_p].p > a[i].p) && (a[short_p].at <= t) && (a[short_p].bt > 0))
            short_p = i;
    a[short_p].bt--;
    if(a[short_p].bt == 0)
    {
        count++;
        a[short_p].wt = t+1 - a[short_p].at - a[short_p].bt;
        a[short_p].tat = t+1 - a[short_p].at;
        total_wt += a[short_p].wt;
        total_tat += a[short_p].tat;
    }
    avg_wt = total_wt*1.0/n;
    avg_tat = total_tat*1.0/n;
    printf("\nP\tAT\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++)
        printf("\n%d\t%d\t%d\t%d\t%d\n",i,a[i].at,a[i].bt,a[i].wt,a[i].tat);
    printf("\nAverage Waiting time =  %f\nAverage Turnaround time =  %f",avg_wt,avg_tat);
    return 0;
}