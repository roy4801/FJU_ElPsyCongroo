#include "epk_disjoint_easy.h"

using namespace std;

#define PDISJ(x) for(int i = 1; i < (x) && (~printf("%d ", p[i])); i++); putchar('\n')

int main()
{
	// 初始化(必須)
	init();
	
	// 將1, 2變成同組
	uni(1, 2);
	// 將2, 3變成同組
	uni(2, 3);

	// 列出前10個的組別
	for(int i = 1; i <= 10; i++)
		printf("%d's group is %d\n", i, find(i));
	
	PDISJ(10);

	return 0;
}