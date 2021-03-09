#include "philosopher.h"

int main() {
	int i;
	srand(time(NULL));

	sem_init(&Limit, 0, 4);

	for (i = 0; i < NUMBER_OF_PHILOSOPHERS; ++i) {
		pthread_mutex_init(&chopsticks[i], NULL);
	}

	for (i = 0; i < NUMBER_OF_PHILOSOPHERS; ++i) {
		pthread_attr_init(&attributes[i]);
	}
	
	for (i = 0; i < NUMBER_OF_PHILOSOPHERS; ++i) {
		pthread_create(&philosophers[i], &attributes[i], philosopher, (void *)(i));
	}

	for (i = 0; i < NUMBER_OF_PHILOSOPHERS; ++i) {
		pthread_join(philosophers[i], NULL);
	}
	return 0;
}

