template<typename T,int N=2>
struct Mat {//Matrix
	unsigned long long v[N][N];
	Mat operator*(Mat b)const {
		Mat val;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				val.v[i][j] = 0;
				for (int k = 0; k < N; k++) {
					val.v[i][j] += v[i][k] * b.v[k][j];
				}
			}
		}
		return val;
	}
	friend ostream& operator<<(ostream& out, Mat m)
	{
	    for(int i = 0; i < N; i++)
          for(int j = 0; j < N; j++)
        	out << m.v[i][j] << (j==N-1 ? "\n" : " ");
	    return out;
	}
};

// 用法
Mat<int> a, b;
    
a.v[0][0] = 1;
a.v[0][1] = 2;
a.v[1][0] = 3;
a.v[1][1] = 4;

b.v[0][0] = 5;
b.v[0][1] = 6;
b.v[1][0] = 7;
b.v[1][1] = 8;
cout << a << b << a*b;