#include <stdio.h>
#include<getopt.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

void FCFS();
void SJF();
void PR();
void RR();

struct node{
    int burst_time;
    int arrival_time;
    int priority;
    struct node *next;
};