#include <bits/stdc++.h>
using namespace std;
using gg = long long;
string biao[]{"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   string stri;
   cin>>stri;
   gg res =0;
   for(auto i: stri) res += (i-'0');
   auto res2 = to_string(res);
   for(gg i=0;i<res2.size();i++){
       if(i) cout<<" ";
       cout<<biao[res2[i]-'0'];
   }
   return 0;
}
