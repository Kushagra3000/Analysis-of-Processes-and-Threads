#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int global = 10;

void *decrease(void * arg){
	int steps=0;
	while(global > -90){
		//printf("%d\n", global);
		global--;
		steps++;
	}
	printf("Global: %d\n", global);
	printf("steps in child: %d\n",steps);
	return NULL;
}

void increase(){
	int steps=0;
	while(global<100){
		//printf("%d\n", global);
		global++;
		steps++;
	}
	printf("Global: %d\n", global);
	printf("steps in parent: %d\n",steps);
}
int main(int argc, char *argv[]){
	pthread_t thread;
	int err;
	err = pthread_create(&thread,NULL,decrease,NULL);
	if(err!=0){
		printf("Can't create thread :[%s]\n",strerror(err));
		exit(0);
	}
	else{
		increase();
		pthread_join(thread,NULL);
	}
	return 0;
}

