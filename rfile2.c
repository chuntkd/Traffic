#include<stdio.h>
int main(int argc, char *argv[])
{
	FILE *fp, *fout;
	char ch;

	if((fp=fopen(argv[1],"r")) ==NULL)	
	{
		fprintf(stderr, "can't open file : %s\n",argv[1]);
		return 1;
	}
	if((fout=fopen("lsout.txt","w")) ==NULL)	
	{
		fprintf(stderr,"can't open file : lsout.txt\n");
		return 1;
	}
	while(1)
	{
		ch = fgetc(fp); // c ==> char 한단어씩 읽는다
		if(ch == EOF)
			break;
		printf("%c",ch);
		fprintf(fout,"%c",ch);
	}
	fclose(fp);
	fclose(fout);
	return 0;
	
}
