#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <unistd.h>
#define RANGE 1048576
#define N_THREADS 4
#define N 200

void  * speak_num ( void *);

void  * speak_num (void * ref_index ) {
	//srand(time(NULL));
	int index = (int ) (*(int *) ref_index );
	for( int j = 0 ; j < N; j++){
		int num = rand() % RANGE;
		printf("person %d : - %d !!\n",index,num);
		sleep(0);
	}

	pthread_exit(NULL);

}
int main (int argc, char ** argv ){ 
	int thread_args[N_THREADS];
	pthread_t peoples[N_THREADS];


	for(int i = 0; i < N_THREADS;i++){
		thread_args[i] = i;
		pthread_create(&peoples[i], NULL, speak_num,(void *)&thread_args[i]);
	}

	for(int i = 0 ; i  < N_THREADS;i++)
		pthread_join(peoples[i],NULL);

	return 0;
}