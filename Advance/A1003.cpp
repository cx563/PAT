#include <bits/stdc++.h>
using namespace std;
using gg = long long;
using arr2 = array<gg,2>;
gg maxn = 6e2;
struct node{
    gg u;
    gg len;
};
vector<vector<node>>adj(maxn);  //  邻接表
vector<gg>weight(maxn),d(maxn),w(maxn),num(maxn),inq(maxn);
gg n, m, start,en,u,v,len;
vector<set<gg>>pre(maxn);   //  结点会多次访问 前驱要记为set 
void dijstra(gg st){
    priority_queue<arr2,vector<arr2>,greater<arr2>>q;
    fill(d.begin(),d.end(),INT_MAX);
    q.push({0,st});
    d[st] = 0;
    while(not q.empty()){
        auto n = q.top();
        q.pop();
        if(n[0] != d[n[1]]) continue;  //  防止旧部松弛
        for(auto& i : adj[n[1]]){
            if(d[n[1]] + i.len < d[i.u]){
                d[i.u] = d[n[1]] + i.len;
                num[i.u] = num[n[1]];
                w[i.u] = w[n[1]] + weight[i.u];
                q.push({d[i.u],i.u});
            }else if(d[n[1]] + i.len == d[i.u]){    //   这里这个被松弛的结点无需入队 因为距离相同 结点相同 
                if(w[n[1]] + weight[i.u] > w[i.u]) {
                    w[i.u] = w[n[1]] + weight[i.u];
                }
                num[i.u] += num[n[1]];
            }
        }
    }
}
void spfa(gg st){
    queue<gg>q;
    q.push(st);
    fill(d.begin(),d.end(),INT_MAX);
    d[st] = 0;
    inq[st] = true;
    while(not q.empty()){
        gg p = q.front();
        q.pop();
        inq[p] = false;
        for(auto& e : adj[p]){
            if(d[e.u] > d[p] + e.len){
                d[e.u] = d[p] + e.len;
                num[e.u] = num[p];
                w[e.u] = w[p] + weight[e.u];
                if(not inq[e.u]){
                    q.push(e.u);
                    inq[e.u] = true;
                }
                pre[e.u].clear();
                pre[e.u].insert(p);
            }else if(d[e.u] == d[p] + e.len){
                if(w[e.u] < w[p] + weight[e.u]){
                    w[e.u] = w[p] + weight[e.u];
                }
                num[e.u] = 0;
                pre[e.u].insert(p);
                for(auto& i : pre[e.u]) num[e.u] += num[i];  //  这里需要重新计算  记前驱
                if(not inq[e.u]){   //  这里和dij不同 这里只是结点 没有距离 如果这个被松弛的点不在队中 也一定要入队
                    q.push(e.u);
                    inq[e.u] = true;
                }
            }
        }
    }
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>m>>start>>en;
   for(gg i=0;i<n;i++) cin>>weight[i];
   while(m--){
       cin>>u>>v>>len;
       adj[u].push_back({v,len});
       adj[v].push_back({u,len});
   }
   num[start] = 1, w[start] = weight[start];
   //spfa(start);
    dijstra(start);
   cout<<num[en]<<" "<<w[en];
   return 0;
}
