#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   map<gg,gg>mp;
   gg ni;
   cin>>ni;
   gg res=0;
   gg tmp;
   for(gg i=0;i<ni;i++){
       cin>>tmp;
       mp[tmp]=i;
   }
   gg left=0;  // 除零以外 没归位的个数
   for(auto i : mp){
       if(i.first !=0 and i.first != i.second) left++;
   }
   auto k = mp.begin();
   while(left){
       if(mp[0] == 0) {
            for(;k!=mp.end();k++){
               if(k->first!=k->second){
                   swap(mp[0],k->second);
                   res++;
                   break;
               }
           }
       }
       swap(mp[mp[0]],mp[0]);
       left--;
       res++;
   }
   cout<<res;
   return 0;
}
