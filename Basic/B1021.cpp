#include <bits/stdc++.h>
using namespace std;
using gg = long long;
map<gg,gg>mp;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   string stri;
   cin>>stri;
   for(auto i:stri){
       mp[i-'0']++;
   }
   for(auto i:mp){
       cout<<i.first<<":"<<i.second<<"\n";
   }
   return 0;
}
