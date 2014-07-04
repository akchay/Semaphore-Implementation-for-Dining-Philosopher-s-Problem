#include<sys/ipc.h>
#include<sys/wait.h>
#include<sys/cdefs.h>
#include<stdio.h>
#include<libsem.h>
#include<unistd.h>
#include <sys/types.h>

int main()
{
	int pid,ret,ret2,ret4;
	
	// definition of variables
    // creating a semaphore with desc 8 
    
	ret=createsem(8);
	
	if(ret==1)
			printf("Yeah its Successful \n");
	else
			printf("Ohh No!!! Its unsuccessful \n");
			
	sleep(2);
		
		{
			
			pid=fork();
			wait(NULL);
			sleep(3);
			
		}
		
if (pid==0)
			{
				printf(" I am the child \n");
				printf(" Child's process ID is = %d \n",(int) getpid());
				ret=createsem(8); 
				sleep(3);
					if(ret==1)
						      printf("Yeah its Successful \n");
					else
							  printf(" Ohh no. Its unsuccessful \n");
			   ret2=fork();
			   wait(NULL);
			   sleep(3);
			   if (ret2==0)
			   {
				   printf("grand child process id= %d \n",(int) getpid());
				   ret=createsem(8);
				   					
				   					if(ret==1)
				   							printf("successful \n");
				   					else
				   							printf("unsuccessfull \n");
				{  
				
			        sleep(2);
					ret4=down(8);
			        sleep(5);
					up(8);
			        sleep(5);
			        close(8);
				    sleep(2);
			    
			    }
			    

			   }
		    }

}


