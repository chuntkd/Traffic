#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
	FILE *fp, *fout;
	char inbuf[200]; // 2nd
	char filename[20]; // 2nd
	char filesize[20]; // 2nd
	char fileowner[20]; // 2nd
	char fileupdate[20]; // 2nd

	if((fp=fopen(argv[1],"r")) ==NULL)	
	{
		fprintf(stderr, "can't open file : %s\n",argv[1]);
		return 1;
	}
	if((fout=fopen("lsout.txt","a")) ==NULL)	// file이 있는지 없는지 확인(a)
	{
		
		if((fout=fopen("lsout.txt","w")) ==NULL)	// 새로운 file 생성(w)
		{
			fprintf(stderr,"can't open file : lsout.txt\n");
			return 1;
		}	
	}
		fgets(inbuf,200,fp); // skip 1st line
		printf("Filename		  size		 	 owner		update\n");
		printf("==============================================================================\n");

	while(1)
	{

		fgets(inbuf,200,fp); // 한라인을 다 읽음
		if (feof(fp)) // end of file
			break;
		strcpy(filename,inbuf+45); // 시작점 부터 끝까지 다 copy (&inbuf[45]) <== 이거도 가능
		filename[strlen(filename)-1] = '\0';

		strncpy(filesize,inbuf+25,6); // 시작점 부터 입력한 숫자만큼 copy

		strncpy(fileowner,inbuf+13,6);
		
		strncpy(fileupdate,inbuf+32,13);
		

		printf("%8s		%8s		%6s		%12s\n",filename,filesize,fileowner,fileupdate);
		fprintf(fout,"%s,%s,%s,%s\n",filename,filesize,fileowner,fileupdate);
	}
	fclose(fp);
	fclose(fout);
	return 0;
	
}
