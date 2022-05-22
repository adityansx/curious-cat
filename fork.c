#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void forkExample() {
	if(fork() == 0) printf("Hello from child!\n");
	else printf("Hello from parent!\n");
	/*
		Child process returns 0, whereas parent process returns 1 or any +ve int
		If -1 is returned, it means the OS wasn't able to produce any child process
	*/
}

int main() {
	forkExample();
	
	return 0;
}