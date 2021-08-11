#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ni;
   cin>>ni;
   vector<gg>v(ni);
   for(auto& i : v) cin>>i;
   gg maxnum =-1;
   unordered_map<gg,gg>left;
   unordered_map<gg,gg>right;
   for(auto& i : v){
       if (i > maxnum) left[i]++;
       maxnum = max(maxnum,i);
   }
   gg minnum = INT_MAX;
   for(gg i = ni-1;i >= 0;i--){
       if (v[i] < minnum) right[v[i]]++;
       minnum = min(minnum,v[i]);
   }
   vector<gg>res;
   for(auto& i : v){
       if(left[i] and right[i]){
           res.push_back(i);
       } 
   }
   sort(res.begin(),res.end());
   cout<<res.size()<<"\n";
   for(gg i=0;i<res.size();i++){
       if(i) cout<<" ";
       cout<<res[i];
   }
   cout<<"\n";   //  这里要注意 没有主元时 这里要单独输出一个空行 输出至少要达到三行
   return 0;
}
