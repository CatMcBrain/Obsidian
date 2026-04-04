#include<stdio.h>

void plus(int *n){
	(*n)++ ;
}

int main(){

int age = 0;

	
	printf("%d\n",age);
	plus(age);
	printf("%d\n",age);
	plus(age);
	printf("%d\n",age);

	return 0;
}