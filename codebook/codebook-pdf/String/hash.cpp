unsigned int BKDRHash(const char str[]){
	// 31 131 1313 13131 131313 etc..
	unsigned int seed = 131;
	unsigned int hash = 0;

	while (*str){
		hash = hash * seed + (*str++);
	}

	return (hash & 0x7FFFFFFF)%1200 ;
}

// C++ build-in hash
hash<string> hash_gen;
size_t num;
num = hash_gen(fuck);
