#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int ret=mkfifo("pub",0664);
    if(ret==-1)
        perror("fifo failed");
    else
        printf("pub is created success\n");
	return 0;
}
