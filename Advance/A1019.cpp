#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ni,di;
   cin>>ni>>di;
   vector<gg>res;
   if(not ni) res.push_back(0);
   while(ni){
       res.push_back(ni % di);
       ni /= di;
   }
   reverse(res.begin(),res.end());
   gg i;
   for(i=0;i<res.size()/2;i++){
       if(res[i] != res[res.size()-1-i]) break;
   }
   if(i != res.size()/2) cout<<"No";
   else cout<<"Yes";
   cout<<"\n";
   for(gg j = 0;j<res.size();j++){
       if(j) cout<<" ";
       cout<<res[j];
   }
   return 0;
}
