#include <bits/stdc++.h>
using namespace std;
using gg = long long;
vector<gg>ufs(1e4 + 10);
void init(){
    iota(ufs.begin(),ufs.end(),0);
}
gg findFather(gg x){
    return x == ufs[x] ? x : ufs[x] = findFather(ufs[x]);
}
void unionSets(gg a,gg b){
    gg fa = findFather(a), fb = findFather(b);
    if(fa != fb) ufs[fa]= fb;
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n,numb = -1,k,pre,b;
   cin>>n;
   while(n--){
       cin>>k>>pre;
       numb = max(numb, pre);
       while(--k){
           cin>>b;
           unionSets(pre,b);
           numb = max(numb, b);
       }
   }
   unordered_map<gg,gg>um;
   for(gg i = 1;i<= numb;i++){
       um[findFather(i)]++;
   }
   cout<<um.size()<<" "<<numb<<"\n";
   gg m,p,q;
   cin>>m;
   while(m--){
       cin>>p>>q;
       if(findFather(p) == findFather(q)) cout<<"Yes\n";
       else cout<<"No\n";
   }
   return 0;
}
