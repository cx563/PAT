#include <bits/stdc++.h>
using namespace std;
using gg = long long;
using arr2 = array<gg,2>;
const gg maxn = 1e4 + 10;
gg n, m, k, dmax, dist;
struct Edge{
    gg u,len;
};
vector<vector<Edge>>adj(maxn);
vector<gg>d(maxn);
gg getNum(string& s){
    return (s[0] == 'G' ? stoll(s.substr(1)) + n : stoll(s));
}
void dijstra(gg st){
    fill(d.begin(),d.end(),INT_MAX);
    priority_queue<arr2,vector<arr2>,greater<arr2>>q;
    q.push({0,st});
    d[st] = 0;
    while(not q.empty()){
        auto n = q.top();
        q.pop();
        if(n[0] != d[n[1]]) continue;
        gg p = n[1];
        for(auto& e : adj[p]){
            if(d[e.u] > d[p] + e.len){
                d[e.u] = d[p] + e.len;
                q.push({d[e.u],e.u});
            }
        }
    }
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>m>>k>>dmax;
   string s1, s2;
   while(k--){
       cin>>s1>>s2>>dist;
       gg k1 = getNum(s1), k2 = getNum(s2);
       adj[k1].push_back({k2,dist});
       adj[k2].push_back({k1,dist});
   }
   gg ans = -1, mind = -1;
   double avgd = INT_MAX; 
   for(gg i=1;i<=m;i++){
       dijstra(n + i);
       gg curmind = *min_element(d.begin() + 1,d.begin() + n + 1);
       gg curmaxd = *max_element(d.begin() + 1,d.begin() + n + 1);
       double curavgd = accumulate(d.begin() + 1,d.begin() + n + 1, 0) * 1.0 / n;
       if(curmaxd <= dmax and curmind > mind or (curmind == mind and curavgd < avgd)){
           ans = i;
           mind = curmind;
           avgd = curavgd;
       }
   }
   if(ans == -1) cout<<"No Solution";
   else{
       cout<<"G"<<ans<<"\n";
       cout<<fixed<<setprecision(1)<<mind * 1.0 <<" "<<setprecision(1)<<avgd;
   }
   return 0;
}
