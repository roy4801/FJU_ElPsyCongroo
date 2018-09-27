// Sparse Table (1-index)
int N = 14, logN = __lg(N), spI = logN+1;
int sp[spI][N] = {0};

void buildST()
{
    // Build the Sparse Table
    for(int i = 0; i < N; i++) // first row (only one in a group)
        sp[0][i] = value[i];
    for(int i = 1; i < spI; i++) // number of elements in a group = 2^i
    {
        for(int j = 0; j < N - ((1 << i) - 1); j++) // j < N - (2^i - 1)
        {
            // Current row overlapped two upper groups in (i-1) row 
            sp[i][j] = max(sp[i-1][j], sp[i-1][j+(1 << (i-1))]);
        }
    }
}

// Query
int query(int l, int r)
{
    l--, r--;

    int distance = r - l + 1;
    int targetIdx = l != r ? __lg(distance)-1 : 0;

    return max(sp[targetIdx][l], sp[targetIdx][r - (1<<targetIdx - 1)]);
}