#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>
#define data "p2:hello"
int main(){
    int fd; 
    fd=open("pub",O_WRONLY);
    if(fd==-1)
        perror("p1data open pub failed");
	else 
		printf("open pub is success\n");
    int flag;
    flag=fcntl(fd,F_GETFL);
    flag|=O_NONBLOCK;
    fcntl(fd,F_SETFL,flag);
    int size=write(fd,data,sizeof(data));
    if(size==-1)
        perror("p1data write failed");
    else
        printf("p1data is send,data is %s\n",data);
    close (fd);
	return 0;
}

