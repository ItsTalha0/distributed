#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<string.h>


/* 
	*this function assumes that the var is array
	*the 0th element is the number elements on which the computation
	are to be done
	*the second element of the array will be used to return the min
	element from the array.
	*the third element is the flag that will be used to tell the
	other process which indicate whether the computations has 
	finished or not
*/

int mint(int * var)
{
	int iter = 0;
	if( var[2] == 1 )
	{
		var[1] = var[3];
		while( iter < var[0] )
		{
			if( var[iter+3] < var[1] )
			{
				var[1] = var[iter+3];
			}
			iter++;
			sleep(1);
		}
		var[2] = 0;
	}
	
	return var[1];
}

int main(int argc,char * argv[]) 
{	
	key_t key = 1234;
	int shmid = shmget(key,1,0);
	if( shmid > 0 )
	{
		int* p =(int *)shmat(shmid,NULL,0);
		printf("%d\n",mint(p));
		shmdt(p);
	}
	else
	{
		printf("shmget failed miserably please go and die in chullu bhar pani.\n");
	}
}


