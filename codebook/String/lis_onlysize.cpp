int main()
{
    int num,times;
    vector<int> vec;
    bool flag = 0;
 
    cin >> times;
    while(times--)
    {
        cin >> num;
        if (!flag)
        {
            vec.push_back(num);
            flag = 1;
        }
        if (vec.back() < num)
        {
            vec.push_back(num);
        }
        else
            *lower_bound(vec.begin(),vec.end(),num) = num;
    }
        printf("%d\n",vec.size());
 
    return 0;
}   

