#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg maxn = 1e3 + 10;
vector<vector<gg>>adj(maxn);
vector<bool>inq(maxn);
gg BFS(gg x, gg level){     //  这种步数模型最好使用BFS进行搜索 特点是 每扩散一次，结果 +1 BFS最短路 
    queue<array<gg,2>>q;
    q.push({x,0});
    inq[x] = true;
    gg num = 0;
    while(not q.empty()){
        auto top = q.front();
        q.pop();
        for(auto i : adj[top[0]]) {
            if(not inq[i]){
                inq[i] = true;
                if(top[1] + 1 <= level){
                    num++;   //  入队才转发
                    q.push({i,top[1] + 1});
                }
            }
        }
    }
    return num;
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n,level,user,follow,k;
   cin>>n>>level;
   for(gg i =1;i<=n;i++){
       cin>>user;
       while(user--){
           cin>>follow;
           adj[follow].push_back(i);
       }
   }
   cin>>k;
   while(k--){
       fill(inq.begin(),inq.end(),false);
       cin>>user;
       cout<<BFS(user,level)<<"\n";
   }
   return 0;
}