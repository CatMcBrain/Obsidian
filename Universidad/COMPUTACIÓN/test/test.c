#include<stdio.h>

void plus(int *n){
	(*n)++ ;
}

int age = 0;

int main(){
	
	FILE *pFile = fopen("file.txt","w");

	fprintf(pFile,"hello \n world");
	
	fclose(pFile);
}