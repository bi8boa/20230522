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
	char buf[1024];
	int size=read(fd,buf,sizeof(buf));
	if(size==-1)
		perror("read failed");
	if((strcmp(buf,"quit"))==0){
		unlink("p1");
		unlink("p2");
	}
	close(fd);
	return 0;
}
