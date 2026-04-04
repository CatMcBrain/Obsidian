#include<stdio.h>

void plus(int *n){
	*n=&n+1 ;
}

int age = 0;

int main(){
	
	printf("%d\n",age);
	plus(age);
	printf("%d\n",age);
	plus(age);
	printf("%d\n",age);

	return 0;
}