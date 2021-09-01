#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg maxn = 1e2 + 10;
gg n,m,s;
struct node{
    vector<gg>child;
    gg val;
};
vector<node>tree(maxn);
vector<gg>res;
void DFS(gg root){
    if(tree[root].child.size() == 0){
        if(accumulate(res.begin(),res.end(),0) == s){
            for(gg i=0;i<res.size();i++){
                if(i) cout<<" ";
                cout<<res[i];
            }
            cout<<"\n";
        }
        return;
    }
    for(auto i : tree[root].child){   //  这个从结点分边 就代表中选中下一个结点
        res.push_back(tree[i].val);
        DFS(i);
        res.pop_back();
    }
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>m>>s;
   for(gg i=0;i<n;i++) cin>>tree[i].val;
   gg id,k,child;
   while(m--){
       cin>>id>>k;
       while(k--){
           cin>>child;
           tree[id].child.push_back(child);
       }
       sort(tree[id].child.begin(),tree[id].child.end(),[](gg a,gg b){
           return tree[a].val > tree[b].val;
       });
   }
   res.push_back(tree[0].val);
   DFS(0);
   return 0;
}
