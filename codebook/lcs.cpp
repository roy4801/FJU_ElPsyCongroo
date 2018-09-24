#include <bits/stdc++.h>
#define LEN 100

using namespace std;


char s1[LEN];
char s2[LEN];
int length[LEN + 1][LEN + 1];
int preve[LEN + 1][LEN + 1]; // 記錄每一格的的結果是從哪一格而來
int lcs[LEN];


void print_LCS_s1(int i, int j)
{
    if (i == 0 || j == 0) return;
 
    if (preve[i][j] == 0)      
    {
        print_LCS_s1(i-1, j-1);
        cout << s1[i]; 
    }
    else if (preve[i][j] == 1)          
    	print_LCS_s1(i, j-1);
    else if (preve[i][j] == 2) 
        print_LCS_s1(i-1, j);
}

void print_LCS_s2(int i, int j)
{
    if (i == 0 || j == 0) return;
 
    if (preve[i][j] == 0)      
    {
        print_LCS_s2(i-1, j-1);
        cout << s2[i]; 
    }
    else if (preve[i][j] == 1)          
    	print_LCS_s2(i, j-1);
    else if (preve[i][j] == 2) 
        print_LCS_s2(i-1, j);
}
 
void LCS(int n1,int n2,char s1[],char s2[])
{

    for (int i = 0; i <= n1; i++) 
    	length[i][0] = 0;
    for (int j = 0; j <= n2; j++) 
    	length[0][j] = 0;
 	
 	
 	if (n1 > n2)
 	{
 		for (int i = 1; i <= n1; i++)
	        for (int j = 1; j <= n2; j++)
	            if (s1[i] == s2[j])
	            {
	                length[i][j] = length[i-1][j-1] + 1;
	                preve[i][j] = 0; // 左上方
	            }
	            else
	            {
	                if (length[i-1][j] < length[i][j-1])
	                {
	                    length[i][j] = length[i][j-1];
	                    preve[i][j] = 1; // 左方
	                }
	                else
	                {
	                    length[i][j] = length[i-1][j];
	                    preve[i][j] = 2; // 上方
	                }
	            }
	    cout << "LCS_length:" << length[n1][n2]  << '\n';
	    cout << "LCS:";
	    print_LCS_s1(n1, n2);
	    //從right down開始
 	}
 	else
 	{
 		for (int i = 1; i <= n2; i++)
	        for (int j = 1; j <= n1; j++)
	            if ( s2[i] == s1[j] )
	            {
	                length[i][j] = length[i-1][j-1] + 1;
	                preve[i][j] = 0; // 左上方
	            }
	            else
	            {
	                if (length[i-1][j] < length[i][j-1])
	                {
	                    length[i][j] = length[i][j-1];
	                    preve[i][j] = 1; // 左方
	                }
	                else
	                {
	                    length[i][j] = length[i-1][j];
	                    preve[i][j] = 2; // 上方
	                }
	            }
	    cout << "LCS_length:" << length[n2][n1]  << '\n';

	        
	    cout << "LCS:";
	    
	    print_LCS_s2(n2, n1);

 	}   
    
}


int main()
{
	#ifdef DBG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif


	int s1_length= 1;
	int s2_length= 1;

	while(scanf("%c",&s1[s1_length]))
	{
		if (s1[s1_length] == '\n')
		{
			break;
		}
		s1_length++;
	}

	while(scanf("%c",&s2[s2_length]))
	{
		if (s2[s2_length] == '\n')
		{
			break;
		}
		s2_length++;
	}


	s1_length--;
	s2_length--;
	LCS(s1_length,s2_length,s1,s2);
	
	return 0;

}
