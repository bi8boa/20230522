#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int fd=open("pub",O_RDWR);
	if(fd==-1)
		perror("open pub failed");
	else
		printf("open pub success\n");
	int fd_p1,fd_p2;
	char buf[1024];
	int size=read(fd,buf,sizeof(buf));
	if(size==-1)
		perror("read failed");
	if((strcmp(buf,"all"))==0){
		fd_p1=open("p1",O_RDWR);
		if(fd_p1==-1)
			perror("open p1 failed");
		else
			printf("open p1 success\n");
		char data[10]="effective";
		int len=write(fd_p1,data,sizeof(data));
		if(len==-1)
			perror("send to p1 failed");
		else 
			printf("send p1 is success,data is %s\n",data);
		fd_p2=open("p2",O_RDWR);
		if(fd_p2==-1)
			perror("open p2 failed");
		else
			printf("open p2 success\n");
		len=write(fd_p2,data,sizeof(data));
		if(len==-1)
			perror("send to p2 failed");
		else 
			printf("send p2 is success,data is %s\n",data);
	}
	close(fd);
	close(fd_p1);
	close(fd_p2);
	return 0;
}
