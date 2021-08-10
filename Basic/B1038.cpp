#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   unordered_map<gg,gg>mp;
   gg ni,qi;
   cin>>ni;
   while(ni--){
       cin>>qi;
       mp[qi]++;
   }
   gg ki;
   cin>>ki;
   for(gg i=0;i<ki;i++){
       cin>>qi;
       if(i) cout<<" ";
       cout<<mp[qi];
   }
   return 0;
}
