#include <stdio.h>
#include <stdlib.h>
struct job {
    int job_number;
    int reqm;
    int numd;
    int reqd;
    int temp2;
    int temp3;
    int timetot;
    int priority;
    struct job *next;
	
	
	};


struct job* job_number(int jobtemp, int reqm, int numd, int temp2, int priority);

void queue1(struct job* jobstart, struct job** x);

void queue2(struct job* jobstart, struct job** x);

struct job* pop1(struct job** x);

struct job* pop2(struct job** x, int jobtemp);