#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include <semaphore.h>

#define NUMBER_OF_PHILOSOPHERS 5

sem_t Limit;

void *philosopher(void *);
void think(int);
void pickUp(int);
void eat(int);
void putDown(int);

pthread_mutex_t chopsticks[NUMBER_OF_PHILOSOPHERS];
pthread_t philosophers[NUMBER_OF_PHILOSOPHERS];
pthread_attr_t attributes[NUMBER_OF_PHILOSOPHERS];