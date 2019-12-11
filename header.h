#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>
#define IMMUNE_TH 1000
#define INCUBATED_TH 100
#define COUNTER_TO_STATE 100
#define INFECTED_TH 300
#define QUARANTINE_TH 400
#define DECEASED_TH 600
#define REMOVED_TH 900
float getRandomNumberFromRange(float, float);
void* child(void*);
int m,i,j,threadCount,inputTurn,quarantine,traditions,turn,counter,barrierTH,turnCount,counterCount,threadHome;
int* subjectsArray;
long thread;
pthread_t *thread_handles;
sem_t count_sem;
sem_t barrier_sem;
pthread_mutex_t myLock1;
//pthread_mutex_t myLock2;
//pthread_mutex_t myLock3;
