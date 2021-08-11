#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ni,mi;
   cin>>ni;
   vector<gg>v1i(ni);
   for(auto& i : v1i) cin>>i;
   cin>>mi;
   vector<gg>v2i(mi);
   for(auto& i : v2i) cin>>i;
   sort(v1i.begin(),v1i.end(),greater<gg>());
   sort(v2i.begin(),v2i.end(),greater<gg>());
   gg res=0;
   gg i=0,j=0;
   while(i<v1i.size() and j < v2i.size() and v1i[i] > 0 and v2i[j] >0){
       res+=v1i[i]*v2i[j];
       i++;
       j++;
   }
   i = v1i.size()-1;
   j = v2i.size()-1;
   while(i>=0 and j >=0 and v1i[i] < 0 and v2i[j] < 0){
       res+=v1i[i]*v2i[j];
       i--;
       j--;
   }
   cout<<res<<"\n";
   return 0;
}
