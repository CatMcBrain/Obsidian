#include<stdio.h>

void vprint (float a[]){
	int len = sizeof(a)/sizeof(a[0]);
	for(int i=0;i<=len;i++){
		printf("%f ", a[i]);
	}
	printf("\n");
}

int main(){

float a[3]={0};
float b[3]={0};
int len = sizeof(a)/sizeof(a[0]);

for(int i=0;i<len;i++){
	printf("#%d de matriz a: ",i+1);
	scanf(" %f", &a[i]);
}
for(int i=0;i<len;i++){
	printf("#%d de matriz b: ",i+1);
	scanf(" %f", &b[i]);
}

vprint(a);
vprint(b);

return 0;
}