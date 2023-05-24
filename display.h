#include <stdio.h>

void printing_completed_job(struct job* done);

void printing_hold_queue(struct job* q1, struct job* q2);

void printing_ready_queue(struct job* ready);

void print_running_process(struct job* running);

void print_waiting_queue(struct job* waiting);
