#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg maxn = 1e3 + 10;
gg n;
void inorder(vector<gg>& v,vector<gg>& res,gg root,gg& index){
    if(root > n) return;
    inorder(v,res,2 * root,index);
    res[root] = v[index++];
    inorder(v,res,2 * root + 1,index);
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   vector<gg>v(n),res(n+1);
   for(auto& i : v) cin>>i;
   sort(v.begin(),v.end());
   gg index =0;
   inorder(v,res,1,index);
   for(gg i =1;i<=n;i++){
       if(i != 1) cout<<" ";
       cout<<res[i];
   }
   return 0;
}
