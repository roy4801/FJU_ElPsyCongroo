// or __gcd(a, b) in gcc
int gcd(int a, int b){
	return a%b?gcd(b,a%b):b;
}
int lcm(int a, int b){
	return a*b/gcd(a,b);
}