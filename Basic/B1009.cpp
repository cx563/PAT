#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   vector<string> v;
   string t;
   while(cin>>t) v.push_back(t);
   reverse(v.begin(),v.end());
   for(gg i=0;i<v.size();i++){
       if(i) cout<<" ";
       cout<<v[i];
   }
   return 0;
}
