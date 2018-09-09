#include "epk_stack_easy.h"

using namespace std;

int main(){
	
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
	push(7);
	push(8);
	printf("%d ",top());

	printf("\n");
	for (int i = 0; i < 10; ++i)
	{
		pop();
		printf("%d",top());
		printf("counter:%d\n",counter);
	}

	push(1);
	push(2);
	push(3);
	push(4);
	printf("%d\n",top());
	pop();
	push(2);
	print();

	return 0;
}
