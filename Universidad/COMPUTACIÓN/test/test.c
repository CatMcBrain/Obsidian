#include <stdio.h>
#include <string.h>

int main()
{
	char x[20]="test";

	printf("Total: %d String: %d", sizeof(x), strlen(x));

	return 0;
} 