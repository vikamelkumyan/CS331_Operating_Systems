#include <stdio.h>

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
} process_t;

void print_gantt(process_t p[], int n) {
    printf("Gantt Chart: |");
    for (int i = 0; i < n; i++) {
        printf(" P%d |", p[i].pid);
    }
    printf("\n");
}

void print_table(process_t p[], int n) {
    int total_wt = 0, total_tat = 0, total_rt = 0;

    printf("PID\tAT\tBT\tWT\tTAT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].arrival_time, p[i].burst_time,
               p[i].waiting_time, p[i].turnaround_time, p[i].response_time);

        total_wt  += p[i].waiting_time;
        total_tat += p[i].turnaround_time;
        total_rt  += p[i].response_time;
    }

    printf("\nAverage Waiting Time: %.2f\n",    (float)total_wt / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat / n);
    printf("Average Response Time: %.2f\n",   (float)total_rt / n);
}

void fcfs(process_t p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (p[j].arrival_time > p[j + 1].arrival_time) {
                process_t temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    int current_time = 0;

    for (int i = 0; i < n; i++) {
        if (current_time < p[i].arrival_time) {
            current_time = p[i].arrival_time;
        }

        p[i].start_time = current_time;
        p[i].completion_time = current_time + p[i].burst_time;
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time    = p[i].turnaround_time - p[i].burst_time;
        p[i].response_time   = p[i].start_time - p[i].arrival_time;
        current_time = p[i].completion_time;
    }
    printf("\nFirst Come First Served (FCFS)\n");
    print_gantt(p, n);
    print_table(p, n);
}

void sjf(process_t p[], int n) {
    int done[n];
    for (int i = 0; i < n; i++) {
        done[i] = 0;
    }

    process_t order[n];
    int current_time = 0;
    int completed = 0;

    while (completed < n) {
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (!done[i] && p[i].arrival_time <= current_time) {
                if (idx == -1 ||
                    p[i].burst_time < p[idx].burst_time ||
                    (p[i].burst_time == p[idx].burst_time &&
                     p[i].arrival_time < p[idx].arrival_time)) {
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            current_time++;
            continue;
        }

        p[idx].start_time = current_time;
        p[idx].completion_time = current_time + p[idx].burst_time;
        p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
        p[idx].waiting_time    = p[idx].turnaround_time - p[idx].burst_time;
        p[idx].response_time   = p[idx].start_time - p[idx].arrival_time;
        current_time = p[idx].completion_time;

        done[idx] = 1;
        order[completed] = p[idx];
        completed++;
    }

    printf("\n=== Shortest Job First (SJF) ===\n");
    print_gantt(order, n);
    print_table(order, n);
}

int main() {
    int n=0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    if (n<=0){
	printf("Invalid number of processes\n");
	return 1;
    }
    process_t processes[n];
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        processes[i].pid = i + 1;
        processes[i].arrival_time = -1;
        processes[i].burst_time = -1;
        printf("Enter the arrival time and burst time for process %d: ", processes[i].pid);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        if (processes[i].arrival_time < 0 || processes[i].burst_time <= 0) {
            printf("Invalid input\n");
            return 1;
        }
    }
    process_t sjf_processes[n];
    for (int i = 0; i < n; i++) {
        sjf_processes[i] = processes[i];
    }

    fcfs(processes, n);
    sjf(sjf_processes, n);
    return 0;
}
