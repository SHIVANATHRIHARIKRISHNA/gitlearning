#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
void main(){
	int fd[2],nbytes,fd1[2];
	char string1[]="Institute";
	char string2[1000];
	scanf("%s",string2);
	printf("%s",string2);
	char res[2000];
	pipe(fd);
	pipe(fd1);
	int id=fork();
	if(id==0){
		close(fd[0]);
		write(fd[1],string2,sizeof(string2));
		close(fd1[0]);
		write(fd1[1],string1,sizeof(string1));
	}
	else{
		close(fd[1]);
		nbytes=read(fd[0],res,sizeof(res));
		//printf("%s\n",res);
		close(fd1[1]);
		nbytes=read(fd1[0],res,sizeof(res));
		printf("%s\n",res);
	}
}
