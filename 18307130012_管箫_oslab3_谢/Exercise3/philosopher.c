#include "philosopher.h"

void *philosopher(void *philosopherNumber) {
	while (1) {
		/*Your code here*/
		think(philosopherNumber);
		sem_wait(&Limit);
		pickUp(philosopherNumber);
		eat(philosopherNumber);
		putDown(philosopherNumber);
		sem_post(&Limit);
	}
}

void think(int philosopherNumber) {
	int sleepTime = rand() % 3 + 1;
	printf("Philosopher %d will think for %d seconds\n", philosopherNumber, sleepTime);
	sleep(sleepTime);
}

void pickUp(int philosopherNumber) {
	// request chopsticks
    /*Your code here*/
	int left = (philosopherNumber + 1) % 5;
	int right = philosopherNumber;
	pthread_mutex_lock(&chopsticks[left]);
	printf("Philosopher %d pick up the chopstick %d\n", philosopherNumber, left);	
	pthread_mutex_lock(&chopsticks[right]);
	printf("Philosopher %d pick up the chopstick %d\n", philosopherNumber, right);
}

void eat(int philosopherNumber) {
	int eatTime = rand() % 3 + 1;
	printf("Philosopher %d will eat for %d seconds\n", philosopherNumber, eatTime);
	sleep(eatTime);
}

void putDown(int philosopherNumber) {
	// release chopsticks
    /*Your code here*/
	int left = (philosopherNumber + 1) % 5;
	int right = philosopherNumber;
	pthread_mutex_unlock(&chopsticks[left]);
	printf("Philosopher %d put down the chopstick %d\n", philosopherNumber, left);
	pthread_mutex_unlock(&chopsticks[right]);
	printf("Philosopher %d put down the chopstick %d\n", philosopherNumber, right);
}