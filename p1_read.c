#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int fd=open("p1",O_RDWR);
    if(fd==-1)
        perror("open failed");
	else
		printf("p1 is open success\n");
    int flag=fcntl(fd,F_GETFL);
    flag|=O_NONBLOCK;
    fcntl(fd,F_SETFL,flag);
    char buf[1024];
	while(1){
		if((read(fd,buf,sizeof(buf)))>0)
		printf("buf=%s\n",buf);
	}
    close(fd);
	return 0;
}
