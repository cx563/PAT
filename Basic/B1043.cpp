#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const string biao = "PATest";
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   unordered_map<char,gg>mp;
   string si;
   cin>>si;
   for(auto i: si){
       mp[i]++;
   }
   
   while(1){
       gg res=0;
       for(auto i : biao){
           if(mp[i]) {
               cout<<i;
               mp[i]--;
           } 
       }
       for(auto i : biao){  // 逻辑应该是 结束之后 再判断表的六个元素的个数
           if(not mp[i]) {
               res++;
           }
       }
       if(res == 6) goto loop;
   }
   loop:;
   return 0;
}
