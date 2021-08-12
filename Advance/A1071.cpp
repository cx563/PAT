#include <bits/stdc++.h>
using namespace std;
using gg = long long;
string convert(string& s){
    for (auto& i : s){
        if (isupper(i)) i +=32;
    }
    return s;
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   string s;
   getline(cin,s);
   map<string,gg>mp;
   for(gg i=0;i < s.size();){
       auto j = find_if(s.begin() + i,s.end(),[] (char ch){
           return isdigit(ch) or isalpha(ch);
       });
       gg pos = j - s.begin(); // 开始下标
       gg end = pos;
       while (end < s.size() and (isdigit(s[end]) or isalpha(s[end]))) end++;   // 左闭右开区间计算长度刚刚好
       string tmp = s.substr(pos,end - pos );
       if (tmp != "") mp[convert(tmp)]++;
       i = end ;
   }
   gg res = -1;
   for (auto i : mp) res = max(res,i.second);
   for (auto i : mp) {
       if (i.second == res) {
           cout<<i.first <<" " << i.second;
           break;
       }
   }
   return 0;
}