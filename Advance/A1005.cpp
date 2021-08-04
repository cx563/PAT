#include <bits/stdc++.h>
using namespace std;
using gg = long long;
string biao[10]{"zero","one","two","three","four","five","six","seven","eight","nine"};
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   string si;
   cin>>si;
   gg res =0;
   for(auto i :si){
       res += i -'0';
   }
   string res2 = to_string(res);
   gg t = res2.size();
   for(gg i=0;i<t;i++){
       if(i) cout<<" ";
       cout<<biao[res2[i]-'0'];
   }
   return 0;
}
