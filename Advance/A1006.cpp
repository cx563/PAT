#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   string res1,res2,namei,starti,endi;
   string a = "24:60:60";
   string b = "0:0:0";
   gg ni;
   cin>>ni;
   while(ni--){
       cin>>namei>>starti>>endi;
       if(starti <a) {
           a= starti;
           res1 = namei;
       }
       if(endi>b){
           b = endi;
           res2 = namei;
       }
   }
   cout<<res1<<" "<<res2;
   return 0;
}
