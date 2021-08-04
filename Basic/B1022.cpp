#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ai,bi,di;
   cin>>ai>>bi>>di;
   vector<gg>res;
   if(ai+bi == 0) res.push_back(0);
   gg t = ai+bi;
   while(t !=0){
       res.push_back(t % di);
       t /= di;
   }
   reverse(res.begin(),res.end());
   for(auto i :res){
       cout<<i;
   }
   return 0;
}
