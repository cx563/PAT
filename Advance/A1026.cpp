#include <bits/stdc++.h>
using namespace std;
using gg = long long;
vector<vector<gg>>adj(505);
vector<bool>vis(505);
void DFS(gg n){
    vis[n] = true;
    for(auto i : adj[n]){
        if(not vis[i]) DFS(i);
    }
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n,m,u,v;
   cin>>n>>m;
   while(m--){
       cin>>u>>v;
       adj[u].push_back(v);
       adj[v].push_back(u);
   }
   DFS(1);
   gg visnum = count(vis.begin() + 1,vis.begin() + n + 1,false);
   gg num = count_if(adj.begin() + 1,adj.begin() + n + 1,[] (vector<gg> a){
       return a.size() % 2 ==1;
   });
   for(gg i=1;i<=n;i++){
       if(i!= 1) cout<<" ";
       cout<<adj[i].size();
   }
   cout<<"\n";
   cout<<(visnum != 0 or (num != 0 and num != 2) ? "Non-Eulerian" : num ? "Semi-Eulerian" : "Eulerian");
   return 0;
}
