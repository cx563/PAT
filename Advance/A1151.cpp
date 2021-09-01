#include <bits/stdc++.h>
using namespace std;
using gg = long long;
unordered_map<gg,gg>um;  //   维护每个元素在中序遍历的下标   便于区分 不再使用 find
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg mi,ni,u,v;
   cin>>mi>>ni;
   for(gg i =0;i<ni;i++){
       cin>>u;
       um[u] = i;
   }
   vector<gg>pre(ni);
   for(gg i=0;i<ni;i++){
       cin>>pre[i];
   }
   while(mi--){
       cin>>u>>v;
       bool f1 = um.count(u),f2 = um.count(v);
       if(not f1 and not f2) cout<<"ERROR: "<<u<<" and "<<v<<" are not found.\n";
       else if(not f1 or not f2){
           cout<<"ERROR: "<<(not f1 ? u : v)<<" is not found.\n";
       }else{
           gg ans = find_if(pre.begin(),pre.end(),[pre,u,v](gg a){   //  这种方法对于先序序列是可行的 我们必须从上到下依次遍历树的根节点
               return (um[a] - um[u]) * (um[a] - um[v]) <= 0;
            }) - pre.begin();
            if(pre[ans] == u or pre[ans] == v){
                if(pre[ans] == v) swap(u,v);
                cout<< u<<" is an ancestor of " <<v<<".\n";
            }else
            cout<<"LCA of "<<u<<" and "<<v<<" is "<<pre[ans]<<".\n";
       } 
   }
   return 0;
}