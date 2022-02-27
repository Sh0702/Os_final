#include <stdio.h>

struct process
{
    int id,at,bt,wt,tat,p;
}

struct process a[10];

int main()
{
    int n,i,j,check_ar=0,cmp_time=0;
    float avg_wt,avg_tat,total_wt,total_tat;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter Arrival Time, Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&a[i].at,a[i].bt,a[i].p);
        a[i].id = i+1;
        if(i==0)
            check_ar = a[i].at;
        if(check_ar != a[i].at)
            check_ar = 1;
    }
    if(check_ar != 0)
    {   
        for(i=0;i<n;i++)
            for(j=0;j<n-i-1;j++)
                if(a[j].at > a[j+1].at)
                {
                    swap(&a[j].at,&a[j+1].at);
                    swap(&a[j].bt,&a[j+1].bt);
                    swap(&a[j].p,&a[j+1].p);
                    swap(&a[j].id,&a[j+1].id);
                }
    }

    if(check_ar != 0)
    {
        a[0].wt = a[0].at;
        a[0].tat = a[0].bt - a[0].at;
        cmp_time = a[0].tat;
        total_wt += a[0].wt;
        total_tat += a[0].tat;
        for(i=1;i<n;i++)
        {
            int min = a[i].p;
            for(j=i+1;j<n;j++)
            {
                if(min > a[j].p && a[j].at <= cmp_time)
                {
                    swap(&a[j].at,&a[i].at);
                    swap(&a[j].bt,&a[i].bt);
                    swap(&a[j].p,&a[i].p);
                    swap(&a[j].id,&a[i].id);
                }
            }
            a[i].wt = cmp_time - a[i].at;
            a[i].tat = a[i].wt + a[i].bt;
            cmp_time += a[i].bt;
            total_wt += a[i].wt;
            total_tat += a[i].tat;
        }
    }
    else
    {
        for(i=0;i<n;i++)
        {
            int min = a[i].p;
            for(j=i+1;j<n;j++)
            {
                if(min > a[j].p && a[j].at <= cmp_time)
                {
                    swap(&a[j].at,&a[i].at);
                    swap(&a[j].bt,&a[i].bt);
                    swap(&a[j].p,&a[i].p);
                    swap(&a[j].id,&a[i].id);
                }
            }
            a[i].wt = cmp_time - a[i].at;
            a[i].tat = a[i].wt + a[i].bt;
            cmp_time += a[i].bt;
            total_wt += a[i].wt;
            total_tat += a[i].tat;
        }
    }
    avg_wt = total_wt*1.0/n;
    avg_tat = total_tat*1.0/n;
    return 0;
}