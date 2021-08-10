#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   unordered_map<char,gg>mp;
   string s1,s2;
   cin>>s1>>s2;
   for(auto i: s1){
       mp[i]++;
   }
   for(auto i : s2){
       mp[i]--;
   }
   gg res=0;
   gg res2=0;
   for(auto i : mp){
       if(i.second<0) res+=i.second;
       else res2+=i.second;
   }
   res ? (cout<<"No "<<-res) :(cout<< "Yes "<<res2); 
   return 0;
}
