/*
 * Template disjoint set implmentation
 * Author: roy4801
 * Team: FJU_ElPsyCongroo
 * ver 0.0.1
 */
#include <iostream>

#define DISJOINT_SIZE 10

/*
 * TODO:
 * 1. Sould make a function return vector<T> that find all group member?
 */

template<typename T>
struct Disjoint
{
	static const int MAX = DISJOINT_SIZE;
	int p[MAX+1];
	T data[MAX+1];

	/*
	 * Disjoint()
	 * Description: Initialize the disjoint set
	 */
	Disjoint()
	{
		for(int i = 0; i < MAX; i++)
		{
			p[i] = i;
		}
	}

	/*
	 * int find(const int x)
 	 * Description: Find the team leader of idx x
	 */
	int find(const int x)
	{
		return x==p[x] ? x : find(p[x]);
	}

	/*
	 * void uni(const int a, const int b)
	 * Description: Make a and b same group
	 */
	void uni(const int a, const int b)
	{
		p[find(a)] = p[find(b)];
	}

	/*
	 * bool equ(const int a, const int b)
	 * Description: If a and b are in the same group
	 */
	bool equ(const int a, const int b)
	{
		return find(a) == find(b);
	}

	/*
	 * T& operator[](const int idx)
	 * Description: Return the reference of the idx-th data
	 */
	T& operator[](const int idx)
	{
		return data[idx];
	}

	/*
	 * T operator[](const int idx) const
	 * Description: Return a copy of the idx-th data
	 */
	T operator[](const int idx) const
	{
		return data[idx];
	}
};