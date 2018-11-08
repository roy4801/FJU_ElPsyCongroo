size_t bkdr(const char str[]){
	// 31 131 1313 13131 131313 etc..
	size_t seed = 131;
	size_t hash = 0;

	while (*str){
		hash = hash * seed + (*str++);
	}

	return (hash & 0x7FFFFFFF);
}

// C++ build-in hash
hash<string> hash_gen;
size_t num = hash_gen(str);