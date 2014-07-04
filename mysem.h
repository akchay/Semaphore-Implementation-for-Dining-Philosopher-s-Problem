#include <malloc.h>

// making a header file for defining the structure of the semaphore



   struct sebuf

// The contents of the structure of semaphore

		{
		
		int procw[NR_PROCS]; // An array to store the processes waiting on a semaphore
		
		int head; // Head to keep track of start of the array
		
		int tail; // Tail to keep track of end of the array
		
		int desc; // the descriptor of the semaphore
		
		int state; // State is 0 or 1
		
		int ref_count; // The number of child processes waiting on the semaphore
		
		int processq; // The Number of processes in the queue.
		
		};


// function definition 

void push(struct sebuf *sem, int num);

int pop(struct sebuf *sem);

// end of function definition







