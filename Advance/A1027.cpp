#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   unordered_map<gg,char> mp;
   for(gg i=0;i<=9;i++) mp[i] = ('0'+i);
   mp[10] = 'A';
   mp[11] = 'B';
   mp[12] = 'C';
   gg ni;
   cout<<"#";
   for(gg i=0;i<3;i++){
       cin>>ni;
       cout<<mp[ni/13]<<mp[ni%13];
   }

   return 0;
}
