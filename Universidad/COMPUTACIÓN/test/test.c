#include <stdio.h>
#include <math.h>

int main()
{
	float r = 4.0;
	float ca = 0;
	float a = 0;
	float v = 0;
	float pi= 3.1416;

	printf("Radius: %f\n", r);

	ca= pi * pow(r,2);
	a= 4.0 * pi * pow(r,2);
	v= (4.0 / 3.0) * pi * pow(r,3);

	printf("Circle: %f Surface : %f Volume: %f", ca, a, v);

	return 0;
} 