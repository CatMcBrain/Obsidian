#include <stdio.h>
#include <string.h>

int main()
{

	char noun[50] = "";
	char verb[50]= "";
	char adjective1[50]= "";
	char adjective2[50]= "";
	char adjective3[50]= "";

	printf("Tell me an adjective: ");
	fgets(adjective1, sizeof(adjective1), stdin);
	printf("\n Tell me an noun: ");
	fgets(noun, sizeof(noun), stdin);
	printf("\n Tell me an adjective: ");
	fgets(adjective2, sizeof(adjective2), stdin);
	printf("\n Tell me an verb (-ing): ");
	fgets(verb, sizeof(verb), stdin);
	printf("\n Tell me an adjective: ");
	fgets(adjective3, sizeof(adjective3), stdin);

	printf(" %s\n", noun);
	printf(" %s\n", adjective1);
	printf(" %s\n", adjective2);
	printf(" %s\n", adjective3);
	printf(" %s\n", verb);


	return 0;
} 