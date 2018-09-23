#include "epk_single-link-list.h"

using namespace std;

int main(int argc, char const *argv[])
{
	
	#ifdef DBG
	freopen("SLL.in","r",stdin);
	freopen("SLL.out","w",stdout);
	#endif

	char symbol;
	int number;

	while( ~scanf("%c %d", &symbol , &number) ){

		if( symbol == 'I' )
			Insert(number);
		else if( symbol == 'D' )
			Delete(number);
		else if( symbol == 'P' )
			Print();
			
	}

	return 0;
}