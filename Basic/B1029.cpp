#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   string s1,s2;
   cin>>s1>>s2;
   unordered_map<char,bool>mp;
   for(auto& i: s1) if(islower(i)) i-=32;   // 都转大写 好判断
   for(auto& i: s2) if(islower(i)) i-=32;   //  这个tolower函数不会改变字符 只会返回相应小写字母的ASSIC码
   for(auto i : s1){
       if(not mp[i] and s2.find(i) == string::npos){
           cout<<i;
       }
       mp[i] = true;
   }
   return 0;
}
