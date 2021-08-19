#include <bits/stdc++.h>
using namespace std;
using gg = long long;
vector<gg> add(vector<gg>& a,vector<gg>& b){
    vector<gg>res;
    gg carry =0;
    for(gg i=0;i<a.size() or i < b.size();i++){   //  必须使用较长边界 不然 高位就无法写入结果
        gg va = (i >= a.size() ? 0 : a[i]);
        gg vb = (i >= b.size() ? 0 : b[i]);
        gg tmp = carry + va + vb;
        res.push_back(tmp % 10);
        carry = tmp / 10;
    }
    while(carry){
        res.push_back(carry % 10);
        carry /= 10;
    }
    return res;
}
bool judge(vector<gg>& v){    //  单个字符串判断回文
    for(gg i=0;i<v.size() / 2;i++){
        if(v[i] != v[v.size() -1 - i]) return false;
    }
    return true;
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   string s;
   gg t,k=0;
   cin>>s>>t;
   vector<gg>num,tmp;
   for(gg i = s.size() - 1;i>=0;i--) num.push_back(s[i] - '0');
   while(k < t and not judge(num)){
       tmp = num;
       reverse(tmp.begin(),tmp.end());
       num = add(num,tmp);
       k++;
   }
   reverse(num.begin(),num.end());
   for(auto i : num) cout<<i;
   cout<<"\n"<<k;
   return 0;
}
