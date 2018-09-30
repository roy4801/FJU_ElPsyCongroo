// #include <bits/stdc++.h>
#include <iostream>

// by SunTalk (TLE also Wrong Answer )

using namespace std;

#define TESTC "1"
#define PROBLEM "C"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

    int number;
	int i;
	int a,b,c;
	int r_a,r_b,r_c;

	while( ~scanf("%d",&number) && number ){

		r_a = r_b = r_c = 0;

		if(number==2){
			r_b=r_c=1;
		}
		else if( number%3 == 0 ){
			r_a = r_b = r_c = number/3; 
		}
		else{
			// printf("else\n");
			b = c = (number/3)+1;
			a = number - b*2;

			for( i = b ; i <= number/2 ; i++ ){
				
				if( a>0 && b%a == 0 ){
					r_a=a;
					r_b=b;
					r_c=c;
					break;
				}
				else if( a==0 && (b+c)==number ){
					r_a=a;
					r_b=b;
					r_c=c;
					break;
				}

				b++;
				c++;
				a=a-2;

			}

		}//end else

		printf("%d %d %d\n",r_a,r_b,r_c );
	}

	return 0;
}