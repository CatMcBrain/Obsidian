#include<stdio.h>

void plus(int *n){
	(*n)++ ;
}

int age = 0;

int main(){
	
	printf("%d\n",age);
	plus(&age);
	printf("%d\n",age);
	plus(&age);
	printf("%d\n",age);

	return 0;
}