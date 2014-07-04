#include <lib.h>
#include <unistd.h>

// calling the system calls

int createsem(int desc)
	  
	  {
	    message m;
	    m.m1_i1= desc; // desc is passed through the system call
	    return ( _syscall(PM_PROC_NR, CREATESEM, &m));
	  }


int close(int desc)

	  {
	    message m;
	    m.m1_i1= desc; // desc is passed through the system call
	    return ( _syscall(PM_PROC_NR, CLOSE, &m));
	  }
	  

int down (int desc)

	     {
	        message m;
	        m.m1_i1=desc; // desc is passed through the system call
	        return(_syscall(PM_PROC_NR, DOWN, &m));
	     }


int up(int desc)

	       {
	         message m;
	         m.m1_i1= desc; // desc is passed through the system call
	         return ( _syscall(PM_PROC_NR, UP, &m));
	       }
	       
       
       
       









