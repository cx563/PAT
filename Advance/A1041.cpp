#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ni;
   cin>>ni;
   vector<gg>vi(ni);
   for(auto& i : vi) cin>>i;
   unordered_map<gg,gg>mp;
   for(auto i : vi) mp[i]++;
   for(auto i : vi){
       if(mp[i]==1) {
           cout<<i;
           return 0;
       }
   }
   cout<<"None";
   return 0;
}