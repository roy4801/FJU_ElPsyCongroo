#include <bits/stdc++.h>

using namsespace std;

unsigned int BKDRHash(const char str[]){
	
	unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
	unsigned int hash = 0;

	while (*str){
		hash = hash * seed + (*str++);
	}

	return (hash & 0x7FFFFFFF)%1200 ;
}

int main(int argc, char const *argv[])
{
	// c++ build-in hash
	string fuck;
	hash<string> hash_gen;
	size_t num;
	num = hash_gen(fuck);

	return 0;
}