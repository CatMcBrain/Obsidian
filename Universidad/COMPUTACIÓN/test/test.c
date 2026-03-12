#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	float in = 0;
	float out = 0;
	int choice = 0;

	printf("Type 1 for kg->pnd or 2 for pnd->kg: ");
	scanf(" %n", &choice);

	if(choice==1){
		printf("How many kg?: ");
		scanf(" %f", &in);
		out=in*2.205;
		printf("The result is: %f pnd", out);
	}
	else if(choice==0){
		printf("How many pnd?: ");
		scanf(" %f", &in);
		out=in/2.205;
		printf("The result is: %f kg", out);
	}
	else{
		printf("Invalid choice.");
	}
} 