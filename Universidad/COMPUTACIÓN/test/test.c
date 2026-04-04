#include<stdio.h>

int main(){
	
	int foo = 1;
	int add = &foo;

	printf("%p", add);

	return 0;
}