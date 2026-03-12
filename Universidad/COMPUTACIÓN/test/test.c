#include <stdio.h>

int main()
{

	char item[50] = "";
	float price = 0;
	int quantity =0;
	char currency[3] ="€";
	float total =0;

	printf("Currency is: %s",currency);

	return 0;
} 

// to change variable permanently, you have to change the value in the adress with &
// no need to do it in fgets, because string is already a pointer (to its first character)

// + € is a string[3], unlike $, so i need to use a string if i want it in a variable