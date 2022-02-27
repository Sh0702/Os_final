#include <stdio.h>

struct process
{
    int p,at,wt,bt,tat;
};

struct process p[10];

void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int i,j,n,check_ar=0,cmp_time,wt,tat;
    float Avg_TAT,Avg_WT;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter Arrival and Burst Time\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&p[i].at,&p[i].bt);
        p[i].p = i+1;
        if(i==0)
            check_ar = p[i].at;
        if(check_ar != p[i].at)
            check_ar = 1;
    }
    if(check_ar != 0)
    {
        for(i=0;i<n;i++)
            for(j=0;j<n-i-1;j++)
                if(p[j].at > p[j+1].at)
                {
                    swap(&p[j].p,&p[j+1].p);
                    swap(&p[j].at,&p[j+1].at);
                    swap(&p[j].bt,&p[j+1].bt);
                }
    }
    if(check_ar == 0)
    {
        p[0].wt = p[0].at;
        p[0].tat = p[0].bt - p[0].at;
        cmp_time = p[0].tat;
        wt += p[0].wt;
        tat += p[0].tat;
        for(i=1;i<n;i++)
        {
            int min = p[i].bt;
            for(j=i+1;j<n;j++)
                if(min < p[j].bt && p[j].at < cmp_time)
                {
                    min = p[j].bt;
                    swap(&p[i].p,&p[j].p);
                    swap(&p[i].at,&p[j].at);
                    swap(&p[i].bt,&p[j].bt);
                }
            p[i].wt = cmp_time - p[i].at;
            wt += p[i].wt;
            cmp_time += p[i].bt;
            p[i].tat = cmp_time - p[i].at;
            tat += p[i].tat; 
        }
    }
    else
    {
        for(i=1;i<n;i++)
        {
            int min = p[i].bt;
            for(j=i+1;j<n;j++)
                if(min < p[j].bt && p[j].at < cmp_time)
                {
                    min = p[j].bt;
                    swap(&p[i].p,&p[j].p);
                    swap(&p[i].at,&p[j].at);
                    swap(&p[i].bt,&p[j].bt);
                }
            p[i].wt = cmp_time - p[i].at;
            wt += p[i].wt;
            cmp_time += p[i].bt;
            p[i].tat = cmp_time - p[i].at;
            tat += p[i].tat; 
        }
    }
    Avg_WT = wt/n;
    Avg_TAT = tat/n;

    // Printing of the results
    printf("The process are\n");
    printf("P\tWT\tTAT\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\n",p[i].p,p[i].wt,p[i].tat);
    }
    
    printf("Avg waiting time is:- %f\n",Avg_WT);
    printf("Avg turn around time is:- %f",Avg_TAT);
    return 0;
}