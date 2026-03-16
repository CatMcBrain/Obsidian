#include <stdio.h>

int main()
{
	int rows=0;
	int cols =0;

	printf("How many rows?: ");
	scanf("%d",&rows);
	printf("How many columns?: ");
	scanf("%d",&cols);

	for(rows;rows>1;rows--){
		for(cols;cols>1;cols--){
			printf("#");
		}
	}

	
	return 0;
}