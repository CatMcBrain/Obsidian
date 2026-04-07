#include<stdio.h>
#include<stdlib.h>
// argv[1]= n-ésimo

int main(int argc, char* argv[]){

float res=0.0;
int num =0;

	for(int i=1;i<=atoi(argv[1]);i++){
		num=0;
		for(int j=1;j<=i;j++){
			res=i%j;
			if(res==0.0){
				num++;
			}
		}
		if(num==2){
			printf("%d\n",i);
		}
	}

	return 0;
}