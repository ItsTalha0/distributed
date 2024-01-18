#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<string.h>


int main(int argc,char * argv[]) 
{	
	int test[] = {34,-20,54,3,10,34,-100,43,3,5};
	key_t key = 1234;
	int sizeof_arr = 13; 
	/*
		so size of array is stored in array[0] 
		and min should be stored in array[1]
		we will need one more variable to indicate whether the 
		searching has finished till now or not.
		so total size of array to be stored is 
	*/
	int shmid = shmget(key,sizeof_arr*sizeof(int),IPC_CREAT | 0666);
	if( shmid > 0 )
	{
		int * p =(int *)shmat(shmid,NULL,0);
		if( p != NULL )
		{
			p[0] = sizeof_arr - 3;
			p[2] = 1;
			for(int i=0;i<p[0];i++)
			{
				p[i+3]=test[i];
			}


			while( p[2] != 0 );
			printf("%d is the min\n",p[1]);
			shmdt(p);
		}
		else
		{
			perror("shmat failed");
		}
		
		int rmid = shmctl(shmid,IPC_RMID,NULL);

	}
	else
	{
		perror("shmget failed");
	}
}


