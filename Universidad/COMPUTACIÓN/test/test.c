#include <stdio.h>

int main()
{

	int age=0;
	float gpa=0.0f;
	char grade='\0';
	char name[30]="";

	printf("Enter your name: ");
	fgets(name, sizeof(name), stdin);

	printf("%s", name);
	printf("Nextline");


	return 0;
}