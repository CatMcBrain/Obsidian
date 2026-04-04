#include<stdio.h>

int main(){
	
	FILE *pFile = fopen("file.txt", "r");

char buffer[1024]={0};

	while(fgets(buffer, 1024,pFile) != NULL){
	printf("%s", buffer);
	}

fclose(pFile);

	return 0;
}