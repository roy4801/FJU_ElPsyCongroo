/*
 * Easy gerenic type Queue Test for ver 0.0.1
 * Author: roy4801
 * Team: FJU_ElPsyCongroo
 *
 * Compile under commands:
 * Linux/*nix/macos: clear && g++ queue_test.cpp -DDBG && ./a.out
 * Windows:          cls && g++ queue_test.cpp -DDBG && a
 */
#include "epk_queue.h"

using namespace std;

// print func for testing purpose only
template<typename T>
void print(Queue<T> &que)
{
	if(!que.empty())
		for(int i = que.fr; i < que.ba; i++)
			printf("%d ", que.d[i]);
	else
		printf("The Queue is empty!");
	putchar('\n');
}

int main()
{
	// Queue<int> que;

	// que.push(10);
	// que.push(20);
	// que.push(30);

	// print(que);

	// while(!que.empty())
	// {
	// 	que.pop();
		
	// 	if(!que.empty())
	// 		printf("After .pop(), front become: %d\n", que.front());
	// }

	// printf("Empty test: %s\n", que.empty() ? "True" : "False");

//-----------------------------------------------------------------------
	Queue<int> que2;
	for(int i = 0; i < 100; i ++)
	{
		que2.push(i);
	}
	printf("front:%d back:%d\n", que2.fr, que2.ba);
	print(que2);
	putchar('\n');
//
	for(int i = 0; i < 100; i ++)
	{
		que2.pop();
	}
	printf("front:%d back:%d\n", que2.fr, que2.ba);
	print(que2);
	putchar('\n');
//
	printf("Before push(1): front:%d back:%d\n", que2.fr, que2.ba);
	que2.push(1);
	printf("After push(1): front:%d back:%d\n", que2.fr, que2.ba);
	print(que2);

	// printf("%d\n", que2.front());
	putchar('\n');
//-----------------------------------------------------------------------
//  Testing for after 100 push & pop and pop again
	Queue<int> que3;
	for(int i = 0; i < 100; i ++)
	{
		que3.push(i);
	}
	for(int i = 0; i < 100; i ++)
	{
		que3.pop();
	}

	printf("front:%d back:%d\n", que3.fr, que3.ba);

	printf("Empty test: %s\n", que3.empty() ? "True" : "False");
	que3.pop();
	que3.push(1);
	printf("front:%d back:%d\n", que3.fr, que3.ba);
	print(que3);

//-----------------------------------------------------------------------

	// printf("\n\n\nWARNING: After push the 101th term into queue\n");
	// que2.push(101);
	// que2.push(102);
	// que2.pop();
	// que2.pop();
	// printf("front:%d back:%d\n", que2.fr, que2.ba);
	// print(que2);

	return 0;
}