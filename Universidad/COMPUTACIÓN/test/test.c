#include <stdio.h>

int main()
{
	int rows=0;
	int cols =0;
	char ch='\0';

	printf("How many rows?: ");
	scanf(" %d",&rows);
	printf("How many columns?: ");
	scanf(" %d",&cols);
	printf("Character?: ");
	scanf(" %c",&ch);


	for(int i=rows;i>0;i--){
		for(int j=cols;j>0;j--){
			printf("%c",ch);
		}
		printf("\n");
	}

	
	return 0;
}