#include <stdio.h>

int main()
{

	int x=1;
	int *px = &x;
	int vx = *px;
	int *pv = &vx;

	printf("x=%d , px=%d , vx= %d , pv=%d", x, px, vx, pv);

	return 0;
} 

// to change variable permanently, you have to change the value in the adress with &
// no need to do it in fgets, because string is already a pointer (to its first character)

// + € is a string[3], unlike $, so i need to use a string if i want it in a variable