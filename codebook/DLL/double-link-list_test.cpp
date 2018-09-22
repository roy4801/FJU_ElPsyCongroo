#include "epk_double-link-list.h"

using namespace std;

int main(int argc, char const *argv[])
{
	
	#ifdef DBG
	freopen("DLL.in","r",stdin);
	freopen("DLL.out","w",stdout);
	#endif

	char symbol;
	int number;

	while( ~scanf("%c %d", &symbol , &number) ){

		if( symbol == 'I' )
			Insert(number);
		else if( symbol == 'D' )
			Delete(number);
		else if( symbol == 'P' ) // the test data for P the number after P is 0
			Print();

	}

	return 0;
}