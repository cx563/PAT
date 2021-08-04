#include <bits/stdc++.h>
using namespace std;
using gg = long long;
map<gg,pair<gg,gg>>mp;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n;
   cin>>n;
   gg ai,bi,ci;
   while(n--){
       cin>>ai>>bi>>ci;
       mp[bi] = {ai,ci};
   }
   cin>>n;
   int ti;
   while(n--){
       cin>>ti;
       cout<<mp[ti].first<<" "<<mp[ti].second<<"\n";
   }
   return 0;
}
