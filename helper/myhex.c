#include<stdio.h>

int main(int argc,char *argv[])
{
	FILE * fp =NULL;
	if( ((fp=fopen(argv[1],"r")) != NULL ))
	{
		char c;
		while( (c=getc(fp)) != EOF )
		{
			if( c == '\n' )
			{
				putchar('\n');
			}
			else
			{
				printf("%x ",c);
			}
		}
		fclose(fp);
	}
	else
	{
		printf("BAD FILE NAME OR FILE DOSNT EXIST\n");
	}

}
