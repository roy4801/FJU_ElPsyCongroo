bitset<40> b;//建10格大小的bitset
int k = 20;
bitset<40> bk(k);//將int直接轉為bitset
string str = "10100110";
bitset<40> bstr(str);//將string直接轉為bitset
// bstr[0] = 1, bstr[1] = 0, bstr[2] = 1, ... , bstr[6] = 1, bstr[7] = 0;

b.reset();//每個位元設0
b.set();//每個位元設1
b[pos] = 1;//第pos個位元設成1
b.count();//有幾個1
b.size();//大小

cin >> b;
//input: "0110xx0011"
//b = "0110"
bitset<8> bb("1001");
cout << bb ;// 00001001