//二數字是否互質
bool isrp(int a, int b){

	if( a == 1 || b == 1 )
		return true;

	while(1){
		int t = a%b;
		if(t == 0) {
			break;
		}
		else{
			a = b;
			b = t;
		}
	}

	if( b > 1 )
		return false;
	else
		return true;
}
