#include<stdio.h>
#include<stdlib.h>

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
		while( getchar() != EOF )//   temp[1] != 0 )
		{
			for( temp[5]=0 ; temp[5]<temp[0] ; temp[5]++ )
			{
				if( ((((1<<temp[5])&buff[temp[5]/8])>>temp[5]) == 1) && temp[5]!=temp[4] )
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
			}
			temp[1] = 0;
			rewind(file[0]);
			fwrite(buff,1,2,file[0]);
		}
		fclose(file[0]);
	}
}



	





