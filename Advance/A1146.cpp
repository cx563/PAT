#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg maxn = 1e3 + 10;
vector<vector<gg>>adj(maxn);
vector<gg>degree(maxn);
vector<gg>tmp, res;
bool isTopSort(vector<gg>& top){
    for(auto i : top){
        if(tmp[i]) return false;
        for(auto j : adj[i]) tmp[j]--;
    }
    return true;
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n,m, u, v, k;
   cin>>n>>m;
   while(m--){
       cin>>u>>v;
       adj[u].push_back(v);
       degree[v]++;
   }
   cin>>k;
   for(gg i=0;i<k;i++){
       vector<gg>top(n);
       for(auto& j : top) cin>>j;
       tmp = degree;
       if(not isTopSort(top)) res.push_back(i);
   }
   for(gg i=0;i<res.size();i++){
       if(i) cout<<" ";
       cout<<res[i];
   }
   return 0;
}
