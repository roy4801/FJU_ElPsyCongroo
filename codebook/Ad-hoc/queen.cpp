#include <bits/stdc++.h>

using namespace std;

int Queen[37000][14];
int Tmp[14];
int total=0;
int Row[14]={0},Left[27]={0},Right[27]={0};

void N_Queen(int k,int Number){
	int i,j;
	if(k==Number){
		for(j=0;j<Number;j=j+1){
			Queen[total][j]=Tmp[j];
		}
		total=total+1;
		return;
	}
	for(i=0;i<Number;i=i+1){ 
		int right= k+i;
		int left= k-i+Number-1;
		if( !Row[i] && !Left[left] && !Right[right] ){
			Row[i]=1;
			Left[left]=1;
			Right[right]=1;

			Tmp[k]=i;

			Eight_Queen(k+1,Number);

			Row[i]=0;
			Left[left]=0;
			Right[right]=0;

		}
	}
}

int main(int argc, char const *argv[]){
    int num;
    cin >> num;
    N_Queen(0,num);
    return 0;
}