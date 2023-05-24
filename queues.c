#include <stdio.h>
#include <stdlib.h>

struct job {
    int jobtemp;
    int reqm;
    int numd;
    int reqd;
    int temp2;
    int temp3;
    int timetot;
    int priority;
    struct job *next;
};

struct job* newjob(int jobtemp, int reqm, int numd, int temp2, int priority) {

    struct job *numjob = (struct job*)malloc(sizeof(struct job));

    numjob->jobtemp = jobtemp;

    numjob->reqm = reqm;

    numjob->numd = numd;

    numjob->reqd = 0;

    numjob->temp2 = temp2;

    numjob->temp3 = 0;

    numjob->timetot = temp2;

    numjob->priority = priority;

    numjob->next = NULL;

    return numjob;
}

void queue1(struct job* numjob, struct job** q1) {
    if(*q1 == NULL) {

        *q1 = numjob;
    }
    else {
        struct job *current = *q1;

        if(numjob->temp2 < current->temp2) {

            numjob->next = *q1;

            *q1 = numjob;
        }
        else {
            while(current->next != NULL) {

                if(numjob->temp2 >= current->temp2) {

                    current = current->next;
                }
            }
            numjob->next = current->next;

            current->next = numjob;
        }  
    }
}

void queue2(struct job* numjob, struct job** q1) {

    if(*q1 == NULL) {

        *q1 = numjob;
    }
    else {
        struct job *current = *q1;

        while(current->next != NULL) {

            current = current->next;
        }
        current->next = numjob;
    }
}

struct job* pop1(struct job** q1) {

    struct job *beg = *q1;

    if(beg == NULL) {

        return NULL;
    }
    *q1 = beg->next;

    beg->next = NULL;

    return beg;
}

struct job* pop2(struct job** q1, int jobstart) {

    struct job *current = *q1;

    while(current != NULL) {

        if(current->next == NULL && current->jobtemp == jobstart) {

            return current;
        }
        if(current->next->jobtemp == jobstart) {

            struct job *end = current->next;

            current->next = end->next;

            end->next = NULL;

            return end;

        }

        current = current->next;
    }
    return NULL;
}
