#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

/*
	this program for now dosnt terminates on the condition mentioned 	in class i.e it wont terminate if info one system is not available with any of the given systems.
	but it will terminate when all the info are present and there is
	no cycle in the info files i.e a have only b's and b have only a's.
*/


int main(int argc,char *argv[])
{
	int temp[6];
	temp[0] = atoi(argv[1]); //total number of systems.
	temp[4] = atoi(argv[2]); //this is the self id.
	FILE *file[2];
	file[0] = fopen(argv[2],"r+");
	unsigned char buff[4];
	buff[0] = buff[1] = buff[2] = buff[3] = 0;
	if( file[0] != NULL )
	{
		fread(buff,1,1,file[0]);
		fread(&buff[1],1,1,file[0]);

		temp[1] = 1; //flag variable.
		temp[2] = 0; //variable for storing the temp count for inner.
		while(    temp[1] != 0 )
		{
			for( temp[5]=0 ; temp[5]<temp[0] ; temp[5]++ )
			{
				if( (((((1<<7)>>temp[5])&buff[temp[5]/8])>>(7-temp[5]) == 1)) && temp[5]!=temp[4] )
				{
					char name[3];
					sprintf(name,"%d",temp[5]);
					printf("%s is the filename\n",name);
					file[1] = fopen(name,"r");
					if( file[1] != NULL )
					{
						fread(&buff[2],1,1,file[1]);
						fread(&buff[3],1,1,file[1]);
						buff[0] = buff[2] | buff[0];
						buff[1] = buff[3] | buff[1];
						fclose(file[1]);
					}
				}
				printf("%x -- \n",buff[0]);
			}
			rewind(file[0]);
			fwrite(buff,1,2,file[0]);
			if( buff[0] == 0xf0 )
			{ 
				temp[1] = 0;
			}
			sleep(1);
		}
		fclose(file[0]);
	}
}



	





