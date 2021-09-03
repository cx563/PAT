#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg maxn = 1e3 + 10;
vector<vector<gg>>adj(maxn);     //  邻接表
vector<bool>flag(maxn);          //  图搜索必须要有这个flag数组
void DFS(gg i){
    flag[i] = true;              //  访问结点
    for(auto j : adj[i]) {       //  访问边  最好在访问边之前就把对应边结点压入路径  进来先更新结果
        if(not flag[j]) DFS(j);
    }
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n,m,k,u,v;
   cin>>n>>m>>k;
   while(m--){    //  建图
       cin>>u>>v; 
       adj[u].push_back(v);
       adj[v].push_back(u);
   }
   while(k--){
       cin>>u;
       fill(flag.begin(),flag.end(),false);
       flag[u] = true;  //   将 u 结点去除
       gg res = 0;
       for(gg i= 1;i <= n;i++){   //   事实上 这个题就是要求去除了某个结点之后整个图的连通块的个数
           if(not flag[i]){
               res++;
               DFS(i);
           }
       }
       cout<<res - 1<<"\n";
   }
   return 0;
}
