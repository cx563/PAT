#include <bits/stdc++.h>
using namespace std;
using gg = long long;
using arr2 = array<gg,2>;
gg n,m,S,D;
const gg maxn = 510;
struct Edge{
    gg u;
    gg len;
    gg cost;
};
vector<vector<Edge>>adj(maxn);
vector<gg>d(maxn,INT_MAX);
vector<gg>c(maxn),pre(maxn),res;
void dijstra(gg st){
    priority_queue<arr2,vector<arr2>,greater<arr2>>q;
    q.push({0,st});
    d[st] = 0;    //   起点是st
    while(not q.empty()){
        auto n = q.top();
        q.pop();
        if(n[0] != d[n[1]]) continue;
        gg p = n[1];
        for(auto& e : adj[p]){
            if(d[e.u] > d[p] + e.len){
                d[e.u] = d[p] + e.len;
                c[e.u] = c[p] + e.cost;
                pre[e.u] = p;
                q.push({d[e.u],e.u});
            }else if(d[e.u] == d[p] + e.len){
                if(c[e.u] > c[p] + e.cost){
                    c[e.u] = c[p] + e.cost;
                    pre[e.u] = p;
                }
            }
        }
    }
}
void DFS(gg n){
    if(n == S){
        res.push_back(n);
        return;
    }
    DFS(pre[n]);
    res.push_back(n);
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>m>>S>>D;
   gg u, v, len, cos;
   while(m--){
       cin>>u>>v>>len>>cos;
       adj[u].push_back({v,len,cos});
       adj[v].push_back({u,len,cos});
   }
   dijstra(S);
   DFS(D);
   for(gg i=0;i<res.size();i++){
       if(i) cout<<" ";
       cout<<res[i];
   }
   cout<<" "<<d[D]<<" "<<c[D];
   return 0;
}
