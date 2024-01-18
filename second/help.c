#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*
	this is the program that will make the context files.
	the code is simple and the standard is not followed here
	as this is just a simple program.
	suppose you want to create one instance file with info of 3 other instances.
	you will first type 
	1
	<enter>
	3
	<enter>
	3 4 5
	<enter>
	
	check the file with 0 name.
*/


int main()
{
	int n_sys = 0;
	printf("enter number of process to be initialised\n");
	scanf("%d",&n_sys);
	int iter = 0;
	while( iter < n_sys )
	{
		printf("building file for %d:",iter);
		int i;
		scanf("%d",&i);
		
		unsigned char store[2];
		store[0] = 0;
		store[1] = 0;
		store[ iter/8 ] = (store[iter/8] | (( 1<<7)>>(iter%8)));
		for(int j=0;j<i;j++)
		{	
			int p;
			scanf("%d",&p);
			store[iter/8] = store[iter/8] | ((1<<7)>>(p%8));
			printf("%x %x is the store val\n",store[0],store[1]);
		}
		char name[4];
		sprintf(name,"%d",iter);
		FILE * fp = fopen(name,"w+");
		fwrite(&store,2,1,fp);
		fclose(fp);
		iter++;
	}
	printf("complete\n");
}

		
