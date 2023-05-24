#include <stdio.h>
#include "queues.h"



void printing_completed_job(struct job* done) {
    printf("How many completed Jobs\n");
    printf("---Break Line---\n");
    printf("Job ID\tArrival Time\tFinish Time\tTurnaround Time\n");
    printf("---Break Line---\n");
    while(done != NULL) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", done->job_number, 0, 0, 0);
        done = done->next;
    }
}

void printing_hold_queue(struct job* q1, struct job* q2) {
    printf("\nHolding Queue Number 1\n");
    printf("---Break Line---\n");
    printf("Job ID\t\tRun Time\n");
    printf("---Break Line---\n");
    while(q1 != NULL) {
        printf("%d\t\t%d\n", q1->job_number, 0);
        q1 = q1->next;
    }
    printf("---Break Line---\n");
    printf("---Break Line---\n");
    printf("Job ID\t\tRun Time\n");
    printf("---Break Line---\n");
    while(q2 != NULL) {
        printf("%d\t\t%d\n", q2->job_number, 0);
        q2 = q2->next;
    }
}

void printing_ready_queue(struct job* ready) {
    printf("\nReady Queue:\n");
    printf("---Break Line---\n");
    printf("Job ID\t\tRun Time\tTime Accrued\n");
    printf("---Break Line---\n");
    while(ready != NULL) {
        printf("%d\t\t%d\t\t%d\n", ready->job_number, ready->temp2, 0);
        ready = ready->next;
    }
}

void print_running_process(struct job* running) {
    printf("\nProcess running on CPU:\n");
    printf("---Break Line---\n");
    printf("Job ID\t\tTime Accrued\tTime Left\n");
    printf("---Break Line---\n");
    if(running != NULL) {
        printf("%d\t\t%d\t\t%d\n", running->job_number, 0, 0);
    }
}

void print_waiting_queue(struct job* waiting) {
    printf("\n\nWait Queue:\n");
    printf("---Break Line---\n");
    printf("Job ID\t\tRun Time\tTime Accrued\n");
    printf("---Break Line---\n");
    while(waiting != NULL) {
        printf("%d\t\t%d\t\t%d\n", waiting->job_number, waiting->temp2, 0);
        waiting = waiting->next;
    }
}

