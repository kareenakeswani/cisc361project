#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXIMUM_PROCESSES 100
#define QUANTUM 1
#define FILE_NAME "input.txt"

typedef struct {
    int job;
    int time_left;
} Process;

// set up rr algorithm
void round_robin(Process *processes, int num_processes) {
    int curr_time = 0;
    bool processes_complete = false;

    while (!processes_complete) {
        processes_complete = true;
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].time_left > 0) {
                processes_complete = false;
                break;
            }
        }

        // checks QUANTUM for each process
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].time_left > 0) {
                printf("Job %d is running at time %d\n", processes[i].job, curr_time);
                processes[i].time_left -= QUANTUM;
                curr_time += QUANTUM;

                // see if process finished
                if (processes[i].time_left <= 0) {
                    printf("Job %d finished execution at time %d\n", processes[i].job, curr_time);
                }
            }
        }
    }
}

int main(void) {
    Process processes[MAXIMUM_PROCESSES];
    int num_processes = 0;
    FILE *input_file = fopen(FILE_NAME, "r");
    if (input_file == NULL) {
        printf("Error: NULL\n");
        return 1;
    }
    char input_letter;
    while (fscanf(input_file, " %c", &input_letter) == 1) {
        if (input_letter == 'A') {
            int arrival, num_job, runtime;
            fscanf(input_file, "%d J=%d R=%d", &arrival, &num_job, &runtime);
            processes[num_processes].job = num_job;
            processes[num_processes].time_left = runtime;
            num_processes++;
        }
    }
    fclose(input_file);
    // execute round robin
    round_robin(processes, num_processes);
    return 0;
}
