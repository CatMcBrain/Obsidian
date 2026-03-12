#include <stdio.h>
#include <math.h>

int main()
{
	float r = 0;
	float ca = 0;
	float a = 0;
	float v = 0;
	float pi= 3.1416;

	printf("Radius: ");
	scanf("%f", &r);

	ca=2*pi*r;
	a=4*pi*pow(r,2);
	v= (4/3)*pi*pow(r,2);

	printf("Circle: %f Surface : %f Volume: %f", ca, a, v);

	return 0;
} 