#include <bits/stdc++.h>
using namespace std;
using gg = long long;
using arr2 = array<gg,2>;
gg maxn = 6e2;
struct Edge{
    gg u;
    gg len;
};
vector<gg>weight(maxn);
vector<vector<Edge>>adj(maxn);
vector<gg>d(maxn,INT_MAX);
vector<vector<gg>>pre(maxn);
vector<gg>path,res;
gg minsendback = INT_MAX, mintakefrom = INT_MAX;
gg cap, n, en, m, u, v, len;
void dijstra(gg s){
    priority_queue<arr2,vector<arr2>,greater<arr2>>q;
    q.push({0,s});  //  第一个一定是离起点的距离 第二个是结点编号
    d[s] = 0;
    while(not q.empty()){
        auto n = q.top();
        q.pop();
        if(n[0] != d[n[1]]) continue;
        gg p = n[1];
        for(auto& e : adj[p]){
            if(d[p] + e.len < d[e.u]){
                d[e.u] = d[p] + e.len;
                pre[e.u].clear();
                pre[e.u].push_back(p);
                q.push({d[e.u],e.u});
            }else if(d[p] + e.len == d[e.u]){
                pre[e.u].push_back(p);
            }
        }
    }
}
void DFS(gg n, gg takefrom, gg sendback){
    if(n == 0){
        for(gg i = path.size() - 2;i >= 0;i--){
            if(weight[path[i]] > cap / 2) sendback += (weight[path[i]] - cap / 2);
            else{
                if(sendback > cap / 2 - weight[path[i]]) sendback -= (cap / 2 - weight[path[i]]);
                else{
                    takefrom += cap / 2 - weight[path[i]] - sendback;
                    sendback = 0;
                }
            }
        }
        if(takefrom < mintakefrom or (takefrom == mintakefrom and sendback < minsendback)) {
           res = path;
           mintakefrom = takefrom;
           minsendback = sendback;
        }
        return;
    }
    for(auto i : pre[n]) { 
        path.push_back(i);
        DFS(i,takefrom,sendback);
        path.pop_back();
    }
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin>>cap>>n>>en>>m;
   for(gg i =1;i<=n;i++) cin>>weight[i];
   while(m--){
       cin>>u>>v>>len;
       adj[u].push_back({v,len});
       adj[v].push_back({u,len});
   }
   path.push_back(en);
   dijstra(0);
   DFS(en,0,0);
   reverse(res.begin(),res.end());
   cout<<mintakefrom<<" ";
   for(gg i=0;i<res.size();i++){
       if(i) cout<<"->";
       cout<<res[i];
   }
   cout<<" "<<minsendback<<"\n";
   return 0;
}
