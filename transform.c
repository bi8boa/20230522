#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int fd; 
    int fd_out;
    fd=open("pub",O_RDWR);
    if(fd==-1)
        perror("open pub failed");
	else
		printf("open pub success\n");
    char* s;
    char buf[1024];
    int size=read(fd,buf,sizeof(buf));
	if(size==-1)
		perror("read pub failed");
	else
		printf("read pub is success,buf is %s\n",buf);
    s=strtok(buf,":");
	printf("s=%s\n",s);
    if(strcmp(s,"p1")==0){
        char data[10]="p2:";
		printf("data=%s\n",data);
        s=strtok(NULL,":");
		printf("s=%s\n",s);
        strcat(data,s);
		printf("data=%s\n",data);
        fd_out=open("p1",O_RDWR);
		if(fd_out==-1)
			perror("open p1 failed");
		else
			printf("open p1 is success\n");
        int size=write(fd_out,data,sizeof(data));
		if(size==-1)
			perror("write faqiled");
		else
			printf("write is success,data is %s\n",data);
    }   
    else if(strcmp(s,"p2")==0){
        char data[10]="p1:";
		printf("data=%s\n",data);
        s=strtok(NULL,":");
		printf("s=%s\n",s);
        strcat(data,s);
		printf("data=%s\n",data);
        fd_out=open("p2",O_RDWR);
		if(fd_out==-1)
			perror("open p2 failed");
		else
			printf("open p2 is success\n");
        int size=write(fd_out,data,sizeof(data));
		if(size==-1)
			perror("write faqiled");
		else
			printf("write is success,data is %s\n",data);
    }
    close(fd);
    close(fd_out);
	return 0;
}
