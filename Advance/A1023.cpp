#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   vector<gg>num,res;   //  用向量来模拟乘法运算
   string s;
   cin>>s;
   for(gg i = s.size() -1;i>=0;i--) num.push_back(s[i] - '0');  //  逆序存储
   gg carry =0;  //  进位
   for(auto i : num){
       res.push_back((i * 2 + carry) % 10);
       carry = (i * 2 + carry) / 10;
   }
   while(carry) {
       res.push_back(carry % 10);
       carry /= 10;
   }
   if(res.size() != num.size()) cout<<"No";
   else{
       gg t = count_if(res.begin(),res.end(),[&num , & res](gg a){    //   长度相等  可以用这种去判断
           return count(res.begin(),res.end(),a) != count(num.begin(),num.end(),a);
       });
       if(not t) cout<<"Yes";
       else cout<<"No";
   }
   cout<<"\n";
   reverse(res.begin(),res.end());
   for(auto i : res)cout<<i;
   return 0;
}
