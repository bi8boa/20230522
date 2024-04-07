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
		perror("open failed");
	char data[10]="quit";
	int len=write(fd,data,sizeof(data));
	if(len==-1)
		perror("write quit to pub failed");
	else
		printf("write quit to pub is success,data is %s\n",data);
	close(fd);
	return 0;
}
