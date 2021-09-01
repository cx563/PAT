#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg maxn = 1e3 + 10;
vector<gg>ufs(maxn);
void init(){
    iota(ufs.begin(),ufs.end(),0);
}
gg findFather(gg x){
    return ufs[x] == x ? x : ufs[x] = findFather(ufs[x]); 
}
void unionSets(gg a, gg b){
    gg fa = findFather(a), fb = findFather(b);
    if(fa != fb) ufs[fa] = fb;
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n,k,h;
   char c;
   cin>>n;
   unordered_map<gg,gg>um;
   init();   //   记得初始化
   for(gg i=1;i<=n;i++){
       cin>>k>>c;
       while(k--){
           cin>>h;
           if(not um.count(h)){
               um[h] = i;
           }else{
               unionSets(i,um[h]);
           }
       }
   }
   um.clear();
   for(gg i=1;i<=n;i++){
       um[findFather(i)]++;
   }
   cout<<um.size()<<"\n";
   vector<gg>res;
   for(auto i : um) res.push_back(i.second);
   sort(res.begin(),res.end(),greater<gg>());
   for(gg i=0;i<res.size();i++){
       if(i) cout<<" ";
       cout<<res[i];
   }
   return 0;
}
