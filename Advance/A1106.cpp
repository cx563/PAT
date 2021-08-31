#include <bits/stdc++.h>
using namespace std;
using gg = long long;
double p,r;
gg mindepth = INT_MAX,num=0;
const gg maxn = 1e5 + 10;
vector<vector<gg>>tree(maxn);
void DFS(gg root,gg depth){
    if(tree[root].size() ==0){
        if(depth < mindepth){
            mindepth = depth;
            num =1;
        }else if(depth == mindepth) num++;
        return;
    }
    for(auto i : tree[root]) DFS(i,depth+1);
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n,k,child;
   cin>>n;
   cin>>p>>r;
   r /= 100;
   for(gg i=0;i<n;i++){
       cin>>k;
       while(k--){
           cin>>child;
           tree[i].push_back(child);
       }
   }
   DFS(0,0);
   cout<<fixed<<setprecision(4)<<p * pow(1 + r,mindepth)<<" "<<num;
   return 0;
}
