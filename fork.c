#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include <stdlib.h>
int global=10;
int steps=0;

int main(){

	pid_t pid = fork();
	
	if(pid<0){
		fprintf(stderr, "Fork failed!\n");
		exit(-1);
	}
	
	if(pid==0){
		while(global<100){
			//printf("%d\n",global);
			global++;
			steps++;
		}
		printf("Value of global in child: %d\n",global);
		printf("Steps: %d\n",steps);
		exit(0);
	}
	else{
		waitpid(pid,NULL,0);
		while(global>-90){
			//printf("%d\n",global);
			global--;
			steps++;
		}
		printf("Value of global in parent: %d\n",global);
		printf("Steps: %d\n",steps);
		exit(0);
	}
}
