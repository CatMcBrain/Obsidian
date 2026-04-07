#include<stdio.h>
int a = 1;
int res = 0;

void plus (int x, int y){
	res=x+y ;
}


int main(){

	int b = 2;
	
	plus(a,b);

	printf("%d\n", res);


return 0;
}