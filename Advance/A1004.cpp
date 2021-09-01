#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg maxn = 1e2 + 10;
vector<vector<gg>>tree(maxn);
vector<gg>res(maxn,-1);
void DFS(gg root,gg level){
    if(res[level] == -1) res[level] =0;
    if(tree[root].size() == 0){
        res[level]++;
        return;
    }
    for(auto i : tree[root]) DFS(i,level+1);
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n,id,m,k,child;
   cin>>n>>m;
   if(not n) return 0;
   while(m--){
       cin>>id>>k;
       while(k--){
           cin>>child;
           tree[id].push_back(child);
       }
   }
   DFS(1,0);
   gg ii = find(res.begin(),res.end(),-1) - res.begin();
   for(gg i = 0;i < ii;i++){
       if(i) cout<<" ";
       cout<<res[i];
   } 
   return 0;
}