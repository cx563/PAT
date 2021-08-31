#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg maxn = 1e5 + 10;
vector<vector<gg>>tree(maxn);
vector<double>date(maxn);
gg n;
double p,r,ans =0;
void DFS(gg root,gg depth){   //  记录深度 可直接避免浮点比较  若浮点比较 建议阈值取 1e-6
    if(tree[root].size() == 0){
        ans += date[root] * pow(1 + r,depth);
        return ; 
    }
    for(auto i : tree[root]) DFS(i,depth + 1);
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg k,child;
   cin>>n>>p>>r;
   r /= 100;
   for(gg i=0;i<n;i++){
       cin>>k;
       if(not k) cin>>date[i];
       else {
           for(gg j=0;j<k;j++){
               cin>>child;
               tree[i].push_back(child);
           }
       }
   }
   DFS(0,0);
   cout<<fixed<<setprecision(1)<<p * ans;
   return 0;
}