#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
void exemplo(){
	int x=1;
	if(fork()==0){
		printf("o x em filho é = %d\n",++x);		
	}
	else{
		printf("o x no pai é = %d\n",--x);
	}
}

int main(){
	exemplo();
	return 0;
}
