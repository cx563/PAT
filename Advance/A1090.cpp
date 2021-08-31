#include <bits/stdc++.h>
using namespace std;
using gg = long long;
double p,r;
int n,maxDepth = 0, num = 0;
const gg maxn = 1e5 + 10;
vector<gg>tree[maxn];
void DFS(gg index,gg depth){
    if(tree[index].size() == 0){
        if(depth > maxDepth){
            maxDepth = depth;
            num = 1;
        }else if(depth == maxDepth){
            num++;
        }
        return ;
    }
    for(auto i : tree[index]){
        DFS(i,depth + 1);
    }
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>p>>r;
   gg father,root;
   r /= 100;
   for(gg i=0;i<n;i++){
       cin>>father;
       if(father != -1)
        tree[father].push_back(i);
       else root = i;
   }
   DFS(root,0);
   cout<<fixed<<setprecision(2)<<p * pow(1 + r,maxDepth)<<" "<<num;
   return 0;
}
