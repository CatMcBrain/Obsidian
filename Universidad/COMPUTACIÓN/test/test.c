#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

	srand(time(NULL));
	printf("%f", rand());
	
	return 0;
}