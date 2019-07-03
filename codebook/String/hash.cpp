size_t BKDRHash(const char str[])
{
	size_t seed = 131; // 31 131 1313 13131 131313 etc..
	size_t hash = 0;
	while (*str) {
		hash = hash * seed + (*str++);
	}
	return hash & 0x7FFFFFFF;
}

// c++ build-in hash
string in;
hash<string> hg;
num = hg(in);