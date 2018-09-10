#include "epk_stack.h"

using namespace std;
/*
* print sequence: from bottom to top.
*
*/
template <typename T>
int print(Stack<T> &stk)
{

	if (!stk.empty())
	{
		for (int i = 0; i <= stk.counter; ++i)
		{
			cout << stk.s[i] << "\n";
		}
	}
	else
	{
		cout << "stack is empty." << "\n";
	}

	
}

struct fuck
{
	int in;
	char ch;
	fuck()
	{
		in = 2;
		ch = '3';
	}
	fuck(int i, char c)
	{
		in = i;
		ch = c;
	}

	ostream& operator<<(ostream& out) 
	{
		out << in << ' ' << ch << '\n';
		return out;
	}
};



int main(int argc, char const *argv[])
{
	Stack <fuck> stk_1;

	stk_1.push(fuck());
	print(stk_1);
	stk_1.push(fuck(1, 'a'));
	print(stk_1);
	stk_1.push(fuck(2, 'a'));
	print(stk_1);
	stk_1.push(fuck(3 ,'a'));
	print(stk_1);

	

	return 0;
}