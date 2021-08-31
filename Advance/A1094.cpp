#include <bits/stdc++.h>
using namespace std;
using gg = long long;
unordered_map<gg,gg>um;
const gg maxn = 1e2 + 10;
vector<gg>level(maxn,1);  //   存储信息的两种方式 结构体 开辟存储结构进行存储
vector<vector<gg>>tree(maxn);
void BFS(gg root){
    queue<gg>q;
    q.push(root);
    while(not q.empty()){
        gg top = q.front();
        q.pop();
        um[level[top]]++;
        for(auto i : tree[top]){
            level[i] = level[top] + 1;
            q.push(i);
        }
    }
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n,m,id,k,child;
   cin>>n>>m;
   while(m--){
       cin>>id>>k;
       while(k--){
           cin>>child;
           tree[id].push_back(child);
       }
   }
   BFS(1);
   gg le,num = -1;
   for(auto i : um){
       if(i.second > num){
           num = i.second;
           le = i.first;
       }
   }
   cout<<num<<" "<<le;
   return 0;
}
