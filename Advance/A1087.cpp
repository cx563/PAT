#include <bits/stdc++.h>
using namespace std;
using gg = long long;
using prr2 = pair<gg,string>;
const gg maxn = 210;
struct Edge{
    string u;
    gg cost;
};
unordered_map<string,vector<Edge>>adj;
unordered_map<string,gg>happy;
unordered_map<string,gg>d,num;
unordered_map<string,vector<string>>pre;
gg n, k, hvalue, len, maxhappy = -1;
double maxavg = -1;
string st, s, u, v;
vector<string>path,res;
void dijstra(string st){
    priority_queue<prr2,vector<prr2>,greater<prr2>>q;
    d[st] = 0;
    q.push({0,st});
    while(not q.empty()){
        auto n = q.top();
        q.pop();
        if(n.first != d[n.second]) continue;
        string p = n.second;
        for(auto& e : adj[p]){
            if(d[e.u] > d[p] + e.cost){
                d[e.u] = d[p] + e.cost;
                q.push({d[e.u],e.u});
                pre[e.u].clear();
                pre[e.u].push_back(p);
                num[e.u] = num[p];
            }else if(d[e.u] == d[p] + e.cost){
                pre[e.u].push_back(p);
                num[e.u] += num[p];
            }
        }
    }
}
void DFS(string s, gg happiness, gg num){
    if(s == st){
        if(happiness > maxhappy or (happiness == maxhappy and happiness * 1.0 / num > maxavg)){
            res = path;
            maxhappy = happiness;
            maxavg = happiness * 1.0 / num;
        }
        return;
    }
    happiness += happy[s];
    num++;
    for(auto i : pre[s]) {
        path.push_back(i);
        DFS(i,happiness,num);
        path.pop_back();
    }
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>k>>st;
   while(--n){
       cin>>s>>hvalue;
       happy[s] = hvalue;
       d[s] = INT_MAX;
       pre[s] = vector<string>(0);
   }
   while(k--){
       cin>>u>>v>>len;
       adj[u].push_back({v,len});
       adj[v].push_back({u,len});
   }
   num[st] = 1;
   dijstra(st);
   path.push_back("ROM");
   DFS("ROM", 0, 0);
   cout<<num["ROM"]<<" "<<d["ROM"]<<" "<<maxhappy<<" "<<(int)maxavg<<"\n";
   reverse(res.begin(),res.end());
   for(gg i=0;i<res.size();i++){
       if(i) cout<<"->";
       cout<<res[i];
   }
   return 0;
}
