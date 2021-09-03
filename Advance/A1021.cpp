#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg maxn = 1e4 + 10;
vector<vector<gg>>adj(maxn);
vector<gg>ufs(maxn);
vector<bool>flag(maxn);
vector<gg>tmp;  //  是 gg 不是 bool 
void init(){
    iota(ufs.begin(),ufs.end(),0);
}
gg findFather(gg x){
    return x == ufs[x] ? x : ufs[x] = findFather(ufs[x]);
}
void unionSets(gg x, gg y){
    gg a = findFather(x), b = findFather(y);
    if(a != b) ufs[a] = b;
}
void DFS(gg u, gg depth, gg& maxDepth){     //   这里 maxDepth 一定要引用 不然会导致反复更新  或者 全局变量
    flag[u] = true;
    if(depth > maxDepth){
        tmp.clear();
        maxDepth = depth;
    }
    if(maxDepth == depth) tmp.push_back(u);
    for(auto i : adj[u]) if(not flag[i]) DFS(i,depth + 1,maxDepth);
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   init();
   gg n,u,v;
   cin>>n;   //   这里的树可以理解为一张无向图
   for(gg i=0;i<n-1;i++){
       cin>>u>>v;
       adj[u].push_back(v);
       adj[v].push_back(u);
       unionSets(u,v);
   }
   unordered_map<gg,gg>um;
   for(gg i=1;i<=n;i++) um[findFather(i)]++;
   if(um.size() != 1) {
       cout<<"Error: "<<um.size()<<" components";
       return 0;
   }
   set<gg>res;   //  这个结果是可能重复的 这里使用set 去重
   gg maxDepth = -1;
   DFS(1,1,maxDepth);
   for(auto i : tmp) res.insert(i);
   fill(flag.begin(),flag.end(),false);
   tmp.clear();
   maxDepth = -1;
   DFS(*res.begin(),1,maxDepth);
   for(auto i : tmp) res.insert(i);
   for(auto i : res) cout<<i<<"\n";
   return 0;
}
