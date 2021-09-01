#include <bits/stdc++.h>
using namespace std;
using gg = long long;
gg LCA  (vector<gg>& pre,gg p,gg q){
    auto t = find_if(pre.begin(),pre.end(),[pre,p,q](gg a){
        return (a - p) * (a - q) <= 0;
    }) ;
    return *t;
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg m,n,p,q;
   cin>>m>>n;
   vector<gg>pre(n);
   for(auto& i : pre) cin>>i;
   while(m--){
       cin>>p>>q;
       gg f1 = count(pre.begin(),pre.end(),p) , f2 = count(pre.begin(),pre.end(),q);
       if(not f1 and not f2) cout<<"ERROR: "<<p<<" and "<<q<<" are not found.\n";
       else if(not f1 or not f2) cout<<"ERROR: "<<(not f1 ? p : q)<<" is not found.\n";
       else{
           gg res = LCA(pre,p,q);
           if(res == p or res == q){
               if(res == q) swap(p,q);
               cout<<p<<" is an ancestor of "<<q<<".\n";
           }else cout<<"LCA of "<<p<<" and "<<q<<" is "<<res<<".\n";
       }
   }
   return 0;
}
