compile:
	gcc fork.c -o f.out
	gcc -o p.out pthread.c -lpthread
fork:
	./f.out
pthread:
	./p.out
clean:
	rm f.out
	rm p.out
