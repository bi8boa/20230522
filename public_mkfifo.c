#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int fd; 
    int ret;
    fd=open("pub",O_RDWR);
    if(fd==-1){
        perror("pub open failed");
    }
	else 
		printf("pub open success\n");
    char buf[1024];
    bzero(buf,sizeof(buf));
    int size=read(fd,buf,sizeof(buf));
    if(size==-1)
        perror("p1 read pub failed");
	else
		printf("p1 read pub success,buf is %s\n",buf);
    char *s=NULL;
	s=strtok(buf,":");
	printf("s=%s\n",s);
    s=strtok(NULL,":");
	printf("s=%s\n",s);
    if(strcmp(s,"p1")==0){
		ret=mkfifo("p1",0664);
        if(ret==-1)
			perror("mkfifo_p1 failed");
        else
            printf("p1_fifo is created\n");
        ret=mkfifo("p2",0664);
        if(ret==-1)
            perror("mkfifo_p2 failed");
		else
            printf("p2_fifo is created\n");
    }
	else if(strcmp(s,"p2")==0){
        ret=mkfifo("p2",0664);
        if(ret==-1)
            perror("mkfifo_p2 failed");
		else
            printf("p2_fifo is created\n");
		ret=mkfifo("p1",0664);
        if(ret==-1)
			perror("mkfifo_p1 failed");
        else
            printf("p1_fifo is created\n");
    }
    close(fd);
	return 0;
}
