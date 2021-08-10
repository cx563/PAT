#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   unordered_map<gg,gg>mp;
   gg ni;
   cin>>ni;
   gg ii,ji;
   char ci;
   while(ni--){
       cin>>ii>>ci>>ji>>ji;
       mp[ii]+=ji;
   }
   gg res=-1;
   for(auto i: mp) res = max(res,i.second);
   for(auto i : mp) if(i.second == res){
       cout<<i.first<<" "<<i.second;
       break;
   }
   return 0;
}
