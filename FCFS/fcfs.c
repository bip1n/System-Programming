/*
WRITE C PROGRAM TO IMPLEMENT FCFS SCHEDULING ALGORITHM
*/

#include <stdio.h>
#include <conio.h>
struct Process{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

void calculateTimes(struct Process processes[], int n) {
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].at) {
            currentTime = processes[i].at;
        }
        processes[i].ct = currentTime + processes[i].bt;
        processes[i].tat= processes[i].ct - processes[i].at;
        processes[i].wt = processes[i].tat - processes[i].bt;
        currentTime = processes[i].ct;
    }
}

void displayProcesses(struct Process processes[], int n) {
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].at,
               processes[i].bt, processes[i].ct, processes[i].tat,
               processes[i].wt);
    }
}

int main() {

    struct Process processes[4];
    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < 4; i++) {
        processes[i].pid = i + 1;
        printf("Arrival time of process %d: ", i + 1);
        scanf("%d", &processes[i].at);
        printf("Burst time of process %d: ", i + 1);
        scanf("%d", &processes[i].bt);
    }

    calculateTimes(processes, 4);
    displayProcesses(processes,4);
    getch();
    return 0;
}
