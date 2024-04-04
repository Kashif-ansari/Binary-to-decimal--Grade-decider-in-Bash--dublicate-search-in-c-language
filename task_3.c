#include<stdio.h>
int main(){

int bt[20],bt2[20],wt[20],tat[20],i,n,p[20],p2[20],k,prt[20],prt2[20],t,ct[20], max;
float wtavg, tatavg, temp,j;
printf("\nEnter the number of processes :");
scanf("%d",&n);
printf("\nEnter the size of the time slice --");
scanf("%d",&t);

for (i = 0;i<n;i++){
p[i]=i;
p2[i]=i;
printf("\nEnter Burst Time and Priority for process %d --",i);
scanf("%d %d",&bt[i], &prt[i]);
ct[i]=bt[i];
prt2[i]=prt[i];
bt2[i]=bt[i];
}
for(i=0;i<n;i++){
for(k=i+1;k<n;k++){
if(bt[i]>bt[k]){
temp=bt[i];
bt[i]=bt[k];
bt[k]=temp;
temp=prt[i];
prt[i]=prt[k];
prt[k]=temp;
temp=p[i];
p[i]=p[k];
p[k]=temp;
}
}
}


wt[0]= wtavg =0;
tat[0] = tatavg = bt[0];
for (i=1;i<n;i++){

wt[i]= wt[i-1] + bt[i-1];
tat[i] = tat[i-1] + bt[i];
wtavg = wtavg + wt[i];
tatavg = tatavg+tat[i];
}
printf("Shortest Job First\n");
printf("\tProcess \t Priority \t Burst Time \t Waiting Time \tTurnaround Time\n");
for(i=0;i<n;i++){
printf("\n\tP%d\t\t%d\t\t%d\t\t%d\t\t%d",p[i],prt[i],bt[i],wt[i],tat[i]);
}
printf("\nAverage Waiting Time --%f",wtavg/n);
printf("\nAverage Turnaround Time --%f\n",tatavg/n);
temp = 0;
printf("\nRound Robin");
max = bt2[0];
for (i=1;i<n;i++){
if(max<bt2[i]){
max=bt2[i];
}
}
for (j=0;j<(max/t)+1;j++){
for (i=0;i<n;i++){
if (bt2[i] != 0){
if (bt2[i] <= t){
tat[i]=temp+bt2[i];
temp=temp+bt2[i];
bt2[i]=0;
}
else{
bt2[i]=bt2[i]-t;
temp=temp+t;
}
}
}
}
for(i=0;i<n;i++){
wt[i]=tat[i]-ct[i];
tatavg+=tat[i];
wtavg+=wt[i];
}
printf("\n\tProcess\t Priority\tBurst Time \tWaiting Time\tTurnAround Time\n");
for(i=0;i<n;i++){
printf("\tP%d \t\t%d\t%d \t\t%d\t\t%d\n",p2[i],prt2[i],ct[i],wt[i],tat[i]);
}
printf("\nThe Average Turnaround Time is --%f",tatavg/n);
printf("\nThe Average Waiting time is --%f",wtavg/n);
}

