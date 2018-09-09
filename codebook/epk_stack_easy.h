/*
 * Easy fixed-size stack implmentation
 * Author: helloworld
 * Team: FJU_ElPsyCongroo
 * ver 0.0.1
 */
#include <cstdio>

#define STACK_SIZE 100

int stk[STACK_SIZE];
int counter = -1;

int top()
{
	return stk[counter];
}

void push(const int n)
{
	stk[++counter] = n;
}
int pop()
{
	if (counter <= 0)
		counter = -1;
	else
		counter--;
}

int size()
{
	return counter + 1;
}

void print(){
	for(int i = 0; i <= counter ; i++)
		printf("%d ",stk[i]);
	printf("\n");
}
