// 用法
// BigNum A,B; cin >> A >> B;
// cout << A+B << A-B;
struct BigNum {
  string num;
  bool sign;
  BigNum(){
    num = "",sign = true;
  }
  BigNum(string k,bool s = true){
    num = k,sign = s;
  }

  friend ostream& operator<<(ostream &out, const BigNum &rhs ){
    if( !rhs.sign )
      out << '-';
    out << rhs.num;
    return out;
  };
  friend istream & operator >> (istream &in, BigNum &rhs ){
    in >> rhs.num;
    if( rhs.num[0] == '-' ){
      rhs.sign = false;
      rhs.num = rhs.num.substr(1,rhs.num.size()-1);
    }

    return in;
  };

  BigNum operator+(BigNum &rhs){
    if( sign && rhs.sign )
      return ADD(num,rhs.num);
    else if( sign && !rhs.sign )
      return SUB(num,rhs.num);
    else if( !sign && rhs.sign )
      return SUB(rhs.num,num);
    else
      return ADD(num,rhs.num,false);
  }
  BigNum operator-(BigNum &rhs){
    if( sign && rhs.sign )
      return SUB(num,rhs.num);
    else if( sign && !rhs.sign )
      return ADD(num,rhs.num);
    else if( !sign && rhs.sign )
      return ADD(num,rhs.num,false);
    else
      return SUB(rhs.num,num);
  }
  BigNum ADD(string lhs,string rhs,bool k = true){
    int carry = 0;
    int a = lhs.size()-1;
    int b = rhs.size()-1;
    BigNum ans;
    ans.sign = k;
    do{
      int one,two;
      one = a>=0 ? (lhs[a]-'0'):0;
      two = b>=0 ? (rhs[b]-'0'):0;
      int tmp = one+two+carry;
      carry = tmp/10;
      tmp %= 10;
      char c = (tmp+'0');
      ans.num = c+ans.num;
      a--,b--;
    }while( a >= 0 || b >= 0 );

    if( carry > 0 ){
      char c = (carry+'0');
      ans.num = c+ans.num;
    }

    return ans;
  }
  BigNum SUB(string lhs, string rhs){

    int carry = 0;
    int a = lhs.size()-1;
    int b = rhs.size()-1;
    BigNum ans;
    if( a < b || ( a == b && lhs < rhs) ){
      ans.sign = false;
      swap(lhs,rhs);
      swap(a,b);
    }
    do{
      int one,two;
      one = a>=0 ? (lhs[a]-'0'):0;
      two = b>=0 ? (rhs[b]-'0'):0;
      int tmp = one-two+carry;
      if( tmp < 0 ){
        tmp += 10;
        carry = -1;
      }
      else
        carry = 0;
      char c = (tmp+'0');
      ans.num = c+ans.num;
      a--,b--;
    }
    while( a >= 0 || b >= 0 );
    while( ans.num[0] == '0' && ans.num.size() > 1 )
      ans.num = ans.num.substr(1,ans.num.size()-1);
    return ans;
  }
};