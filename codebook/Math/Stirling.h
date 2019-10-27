double Stirling(int n){
	return (0.5*log(2.0*acos(-1.0)*n)+n*log(n+0.0)-n)/log(10.0);
}// n! 的位數