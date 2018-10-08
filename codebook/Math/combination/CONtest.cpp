#include "Combination_of_Numbers.h"

using namespace std;

int Times(int k){

	if( k == 0 )
		return 1;
	else if( k%2 == 0 )
		return Times(k/2)*Times(k/2);
	else
		return Times(k/2)*Times(k/2)*2;
}

int main(int argc, char const *argv[])
{

	freopen("table.out","w",stdout);

	Build(4,7);

	for(int i=1;i<Times(17)-1;i++){
		printf("%lld\n",table[i] );
	}

	return 0;
}