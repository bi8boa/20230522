#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>
#define login "login:p1"
int main(){
    int fd; 
    fd=open("pub",O_RDWR);
    if(fd==-1)
        perror("p1login open pub failed");
    else
        printf("p1login open pub success\n");
    int flag;
    flag=fcntl(fd,F_GETFL);
    flag|=O_NONBLOCK;
    fcntl(fd,F_SETFL,flag);
    int size=write(fd,login,strlen(login));
    if(size>0)
        printf("login:p1 is sending\n");
    else
        perror("p1login send failed");
    close (fd);
	return 0;
}
