#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   unordered_map<gg,gg>mp;
   gg ni;
   for(gg i=0;i<10;i++){
       cin>>ni;
       mp[i] = ni;
   }
   for(gg i=1;i<10;i++){
       if(mp[i]) {
           cout<<i;
           mp[i]--;
           break;
       }
   }
   for(gg i=0;i<10;i++){
       while(mp[i]){
           cout<<i;
           mp[i]--;
       }
   }
   return 0;
}
