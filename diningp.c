#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <lib.h>
#include <sys/cdefs.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <libsem.h>


#define MIN_THINK 1
#define MAX_THINK 7
#define MIN_EAT 1
#define MAX_EAT 7

#define  N 5   /* number of philosophers */

#define  LEFT (i+N-1)%N   /* number of i's left neighbor */

#define  RIGHT (i+1)%N   /* number of i's right neighbor */

#define  THINKING 0   /* philosopher is thinking */

#define  HUNGRY   1 /* philosopher is trying to get forks */

#define  EATING   2 /* philosopher is eating */

int  *status; /* a pointer to keep track of the states of the philosophers */

int shmid;
key_t key;
int time;
char t;
int l;

// prototypes of the functions

void philosopher (int);
void put_forks(int);
void test (int);
void take_forks(int);

// end of the function prototypes


int diningphilosopher()
{
	status= shmat(shmid, (void *)0, 0);
	
	for(int i=0;i<N;i++)
		{
		createsem(i);
		}

for(int i=0;i<N; i++)
		
		{
		// All the philosophers are thinking initially
		status[i]=THINKING;
		}


for(int i=0;i<N;i++)
	
		{
			int a =fork();
				if(a!=0)
					{
					
					// I am in the parent 
					
					}
				else
			       {
					down(i);
					philosopher(i);
					printf("status of philosopher %d = %d\n", i+1, status[i]);
					}

		}
		
		return 0;
		
		} // end of dining philosopher function 


void take_forks(int i) /* i: philosopher number, from 0 to N1 */

	{
		down(N); /* enter critical region */
		status[i] = HUNGRY; /* record fact that philosopher i is hungry */
		printf("philosopher %d is hungry\n", i+1);
		test(i); /* try to acquire 2 forks */
		sleep(3);
		up(N); /* exit critical region */
		down(i); /* block if forks were not acquired */
	}

void put_forks(int i) /* i: philosopher number, from 0 to N1 */

	{
	
		down(N); /* enter critical region */
		status[i] = THINKING; /* philosopher has finished eating */
		test(LEFT); /* see if left neighbor can now eat */
		sleep(3);
		test(RIGHT); /* see if right neighbor can now eat */
		sleep(3);
		up(N); /* exit critical region */
		
	}


void test(int i)   /* i: philosopher number, from 0 to N1 */

	{
		if (status[i] == HUNGRY && status[LEFT] != EATING && status[RIGHT] != EATING)
			    {
					status[i] = EATING;
					up(i);
				}
	}



void philosopher(int i) /* i: philosopher number, from 0 to N1 */
	
	{
	    
		printf("Philosopher %d is thinking\n", i+1);
		time=rand() % MAX_THINK + MIN_THINK;            /* philosopher is thinking */
		sleep(time);
		take_forks(i);                /* acquire two forks or block */
		printf("Philosopher %d is eating\n", i+1); 
		time=rand() % MAX_EAT + MIN_EAT;
		sleep(time);
		printf("Philosopher %d is done eating and back to thinking\n", i+1);
		put_forks(i);
	
	}




int main(void)

{

int in;
printf("Enter the number of tables you want \n");
scanf("%d", &in);
int k[in];
key_t key;

// generating a random key for shared memory
key=(int)(rand()%100+1);

// creating a shared memory of 1000 bytes
shmid = shmget(key, 1000 , 0644 | IPC_CREAT);



for(int i=0; i<in;i++)
{

	 int a=fork();
	
	 if(a!=0)
	 {
	 
	 // I am in the parent 
	 
	 }
	 else
	 
	 {
	 
	 printf("Hey you are welcomed to the Dining Philosopher Demo \n");
	 printf("The number of the table is %d \n", i+1);
	 
	 // function is called
	 diningphilosopher(); 
     
     
	}
}

return 0;
// end of main function

}

