#include<stdio.h>
#include<string.h>

struct test{
	char name[10];
	int num;
};

int main(){
	
	struct test foo1 = {"foo1",1};
	struct test foo2 = {"foo2",2};

	struct test foos[]= {foo1, foo2};
	int len=sizeof(foos)/sizeof(foos[0]);

	for(int i=0;i<len;i++){
		printf("%s\n",foos[i].name);
		printf("%d\n",foos[i].num);
	};

	return 0;
}