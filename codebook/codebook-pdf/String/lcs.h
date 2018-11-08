// LCString
string LCStr(string &s1, string &s2)
{
  string rec;
  int arr[100][100];

  memset(arr, 0, sizeof(arr));

  int maxx = 0;
  int position = 0;

  for (int i = 1; i <= s1.length(); ++i)
  {
    for (int j = 1; j <= s2.length(); ++j)
    {
      if (s1[i-1] == s2[j-1])
      {
        arr[i][j] = arr[i-1][j-1] + 1;

        if (maxx < arr[i][j])
        {
          position = i;
          maxx = arr[i][j];
        }
      }
      else
      {
        arr[i][j] = 0;
      }
    }
  }
  for (int k = position - maxx; k < position; ++k)
  {
    rec += s1[k];
  }
  return rec;
}