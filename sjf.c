#include <stdio.h>

struct Process {
    char pid[5];
    int at, bt, ct, wt, tat, done;
};

int main() {
    int n, i, completed = 0, time = 0;
    float total_wt = 0, total_tat = 0;

    scanf("%d", &n);

    struct Process p[n];

    for(i = 0; i < n; i++) {
        scanf("%s %d %d", p[i].pid, &p[i].at, &p[i].bt);
        p[i].done = 0;
    }

    while(completed < n) {
        int idx = -1;
        int min_bt = 9999;

        for(i = 0; i < n; i++) {
            if(p[i].at <= time && p[i].done == 0) {
                if(p[i].bt < min_bt) {
                    min_bt = p[i].bt;
                    idx = i;
                }
            }
        }

        if(idx == -1) {
            time++;
        } else {
            time += p[idx].bt;
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            p[idx].done = 1;

            total_wt += p[idx].wt;
            total_tat += p[idx].tat;

            completed++;
        }
    }

    printf("Waiting Time:\n");
    for(i = 0; i < n; i++)
        printf("%s %d\n", p[i].pid, p[i].wt);

    printf("Turnaround Time:\n");
    for(i = 0; i < n; i++)
        printf("%s %d\n", p[i].pid, p[i].tat);

    printf("Average Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}