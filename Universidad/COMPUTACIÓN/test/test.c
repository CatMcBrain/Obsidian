#include<stdio.h>
#include<string.h>

struct test{
	char name[10];
	int num;
};

int main(){
	
	struct test foo1 = {0};
	strcpy(foo1.name, "myname");

	printf("%s\n",foo1.name);
	printf("%d",foo1.num);

	return 0;
}