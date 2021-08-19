#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct node{
    gg rank;
    gg weight;
    gg id;
};
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg p,g,tmp;
   cin>>p>>g;
   unordered_map<gg,node>mp;
   for(gg i=0;i<p;i++){
       cin>>mp[i].weight;
       mp[i].id = i;
   }
   vector<node>tt;   //  初始序列
   for(gg i=0;i<p;i++){
       cin>>tmp;
       tt.push_back(mp[tmp]);
   }
   vector<vector<node>>res;
   while(1){
       vector<node>t;   //  晋级者
       for(gg i=0;i<tt.size();){
            auto j = max_element(tt.begin()+i,tt.begin() + min((long long)tt.size(),i+g), [] (const node& a, const node& b){
                return a.weight < b.weight;
            });
            t.push_back(*j);
            i = i + g;
       }
       for(auto i : t){
          auto j = find_if(tt.begin(),tt.end(),[i](const node& a){
              return a.weight == i.weight;
          });
          tt.erase(j);
       }
       res.push_back(tt);
       tt = t;   //  下一次轮回
       if(tt.size() == 1){
           res.push_back(tt);
           break;
       }
   }
   gg r = 1;
   vector<node>ress;
   for(gg i = res.size()-1;i>=0;i--){
       for(auto& i : res[i]){
           i.rank = r;
           ress.push_back(i);
       }
       r += res[i].size();
   }
   sort(ress.begin(),ress.end(),[] (const node& a, const node& b){
       return a.id < b.id;
   });
   for(gg i=0;i<p;i++){
       if(i) cout<<" ";
       cout<<ress[i].rank;
   }
   return 0;
}
