#include <bits/stdc++.h>
using namespace std;
using gg = long long;
gg ni;
pair<string,gg> convert(const string& s){
    string str;  // 尾数
    gg e;    //  指数
    gg pos = s.find('.');   // 寻找小数点的位置
    if (pos == string::npos) {   // 没有小数点,显然是一个整数
        str = (s.size() < ni ? s + string(ni - s.size(),'0') : s.substr(0,ni)); 
        e = s.size();
    }else{                  //  数字有小数点e
        if (pos == 1 and s[0] == '0'){   //  这里判断的不严谨 0.1 1.2  显然 分类是不正确的
            gg i = 2;
            while (i < s.size() and s[i] == '0') i++;  // 去除前导0
            string tmp = s.substr(i);
            str = (tmp.size() < ni ? tmp + string(ni - tmp.size(),'0') : tmp.substr(0,ni));
            e = (i == s.size() ? 0 : -(i-2) );
        }else{
            string tmp = s.substr(0,pos) + s.substr(pos+1);
            e = pos;
            str = (tmp.size() < ni ? tmp + string(ni - tmp.size(),'0') : tmp.substr(0,ni));
        }               
    }
    return {str,e};
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   string a, b;
   cin >> ni >> a >> b;
   while (a.size() >=2 and a[0] == '0' and a[1] != '.') a.erase(a.begin());
   while (b.size() >= 2 and b[0] == '0' and b[1] != '.') b.erase(b.begin());
   if (a == "0") a += '.';
   if (b == "0") b += '.';
   auto resa = convert(a);
   auto resb = convert(b);
   if (resa == resb)  cout<<"YES"<<" "<<"0."<<resa.first<<"*10^"<<resa.second ;
   else cout<<"NO"<<" "<<"0."<<resa.first<<"*10^"<<resa.second<<" 0."<<resb.first<<"*10^"<<resb.second; 
   return 0;
}
