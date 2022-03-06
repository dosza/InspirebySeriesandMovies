/*
	Author: Daniel Oliveira Souza
	Description: Simulte four people speak pseudo ramdon numbers (based on Doctor who series 10 episode  6 "Extremis")
	Date: 03/05/2022
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define RANGE 1048576
#define N_THREADS 4
#define N 20

void  * speak_num ( void *);
void simulate();

int main (int argc, char ** argv ){ 
	simulate();
	return 0;
}

// people speak pseudo numbers
void  * speak_num (void * ref_index ) {
	int index = (int ) (*(int *) ref_index );

	for( int j = 0 ; j < N; j++){
		srand(time(NULL));
		int num = rand() % RANGE;
		printf("person %d : -\t%d !!\n",index,num);
		sleep(1);
	}

	pthread_exit(NULL);
}

//create and start  threads (init simulate)
void simulate(){
	int thread_args[N_THREADS];
	pthread_t peoples[N_THREADS];

	for(int i = 0; i < N_THREADS;i++){
		thread_args[i] = i;
		pthread_create(&peoples[i], NULL, speak_num,(void *)&thread_args[i]);
	}

	for(int i = 0 ; i  < N_THREADS;i++)
		pthread_join(peoples[i],NULL);
}