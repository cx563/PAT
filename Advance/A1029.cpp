#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg a,b;
   cin>>a;
   vector<gg>v1(a);
   for(auto& i : v1) cin>>i;
   cin>>b;
   vector<gg>v2(b);
   for(auto& i : v2) cin>>i;
   vector<gg>res(v1.size()+v2.size());
   merge(v1.begin(),v1.end(),v2.begin(),v2.end(),res.begin());
   cout<<res[(res.size()-1)/2];
   return 0;
}
