#include <bits/stdc++.h>
using namespace std;
using gg = long long;
map<gg,gg>mp;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ni;
   cin>>ni;
   gg name,score; 
   while(ni--){
       cin>>name>>score;
       mp[name]+=score;
   }
   gg res1,res2 = -1;
   for(auto i :mp){
       if(i.second >res2){
           res2 = i.second;
           res1 = i.first;
       }
   }
   cout<<res1<<" "<<res2;
   return 0;
}
