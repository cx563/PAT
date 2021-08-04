#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   vector<gg> t(3);
   char c;
   gg ty,ts;
   cin>>t[0]>>c>>t[1]>>c>>t[2];
   ty = t[0]* 17* 29 + t[1] * 29 + t[2];
   cin>>t[0]>>c>>t[1]>>c>>t[2];
   ts = t[0]* 17* 29 + t[1] * 29 + t[2];
   if(ts - ty <0) cout<<"-";
   gg res = (ts- ty <0 ? ty-ts:ts -ty);
   cout<<res/(17*29)<<"."<<res%(17*29)/29<<"."<<res % 29;
   return 0;
}
