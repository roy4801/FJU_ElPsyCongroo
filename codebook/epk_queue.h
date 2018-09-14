/*
 * Easy gerenic type Queue implmentation
 * Author: roy4801
 * Team: FJU_ElPsyCongroo
 * ver 0.0.1
 */
#include <iostream>

#ifdef DBG
#include <assert.h>
#endif

#define N 100

template <typename T>
struct Queue
{
	static const int MAX = N;
	T d[MAX];
	int fr, ba;

	Queue()
	{
		fr = ba = 0;
	}
	T front()
	{
		#ifdef DBG
		assert(fr != ba);
		#endif
		return d[fr];
	}
	T back()
	{
		#ifdef DBG
		assert(fr != ba);
		#endif
		return d[ba-1];
	}
	void pop()
	{
		if(fr >= Queue::MAX)
			fr %= Queue::MAX;
		else
			if(!empty())
				fr++;
	}
	void push(const T &n)
	{
		if(ba >= Queue::MAX)
		{
			ba %= Queue::MAX;
			pop();
		}
		
		d[ba++] = n;
	}
	bool empty()
	{
		return fr == ba;
	}
	int size()
	{
		return ba - fr;
	}
};