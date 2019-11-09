#define MAXN 10000
//MAXN 數量為有幾個字串X多少字元
#define character 26
struct trie{
        
    int siz;
    int node[MAXN+5][character+5];

    void init(){
        siz = 1;
        memset(node[0], 0, sizeof(node[0]));
    }

    int idx(char k){//here is a-z
        return k-'a';
    }

    void insert(string str){
        int dep = 0;
        for(int i = 0 ; i < str.size() ; i++ ){
            int span = idx(str[i]);
            if( node[dep][span] == 0 ){
                memset(node[siz],0,sizeof(node[siz]));
                node[dep][span] = siz++;
            }
            dep = node[dep][span];
        }
    }

}tree;