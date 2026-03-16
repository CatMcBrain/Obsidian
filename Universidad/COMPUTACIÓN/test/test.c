#include <stdio.h>

int main()
{
	int rows=0;
	int cols =0;

	printf("How many rows?: ");
	scanf("%d",&rows);
	printf("How many columns?: ");
	scanf("%d",&cols);

	for(rows;rows>0;rows--){
		for(cols;cols>0;cols--){
			printf("#");
		}
		printf("%d",rows);
	}

	
	return 0;
}