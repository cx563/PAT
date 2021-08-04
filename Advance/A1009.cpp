#include <bits/stdc++.h>
using namespace std;
using gg = long long;
map<int,double,greater<gg>>pa,ans;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   int k;
   cin>>k;
   int ai;
   double pi;
   while(k--){
       cin>>ai>>pi;
       pa[ai] += pi;
   }
   cin>>k;
   while(k--){
       cin>>ai>>pi;
       for(auto i : pa){
           ans[i.first+ai] += i.second* pi;
       }
   }
   for(auto i = ans.begin() ;i != ans.end();){
       if(i->second == 0) ans.erase(i);
       else i++;
   }
   if(ans.empty()) cout<<"0";
   else {
       cout<<fixed<<setprecision(1);
       for(auto i:ans){
           cout<<" "<<i.first<<" "<<i.second;
       }
   }
   return 0;
}
