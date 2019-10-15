struct LIS{
    
    int table[MAXN+5];
    int seat[MAXN+5];
    vector <int> _LIS_;
    vector <int> output;

    LIS(){
        memset(table, 0, sizeof(table));
        memset(seat, 0, sizeof(seat));
    }

    void Build(){
        _LIS_.push_back(table[0]);
        for(int i = 1 ; i < table.size() ; i++ ){
            if( table[i] > _LIS_.back() ){
                _LIS_.push_back(table[i]);
                seat[i] = _LIS_.size()-1;
            }
            else{
                *lower_bound(_LIS_.begin(),_LIS_.end(),table[i]) = table[i];
                seat[i] = lower_bound(_LIS_.begin(),_LIS_.end(),table[i])-_LIS_.begin();
            }
        }
    }

    int length(){
        return _LIS_.size();
    }

    void real_LIS(){
        stack <int> S;
        int k = _LIS_.size()-1;
        for(int i = table.size()-1; i >= 0 ; i-- ){
            if( seat[i] == k ){
                k--;
                S.push(table[i]);
            }
        }
        while( !S.empty() ){
            output.push_back(S.top());
            S.pop();
        }
        for(int i = 0 ; i < output.size() ; i++ ){
            printf("%d%c",output[i],i==output.size()-1 ? '\n':' ');
        }
    }

}