/*
 * Easy gerenic type Stack implmentation
 * Author: helloworld
 * Team: FJU_ElPsyCongroo
 * ver 0.0.1
 */
#include <iostream>

#ifdef DBG
#include <assert.h>
#endif

#define N 100

template <typename T>

struct Stack
{
	static const int MAX = N;
	T s[MAX];
	int counter;

	Stack()
	{
		counter = -1;
	}
	T top()
	{
		#ifdef DBG
		assert(counter == -1);
		#endif
		return s[counter];

	}
	void pop()
	{
		if (counter <= 0)
			counter = -1;
		else
			counter--;
	}
	void push(const T &n)
	{
		if (counter >= Stack::MAX)
		{
			#ifdef DBG
			assert(counter == -1);
			#endif
		}
		else
			s[++counter] = n;
	}
	bool empty()
	{
		if (counter == -1)
			return true;
		else
			return false;
	}
	int size()
	{
		return counter + 1;
	}
};