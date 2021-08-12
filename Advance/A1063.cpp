#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ni, num, element, i=1;
   cin >> ni;
   unordered_map<gg,set<gg>>mp;
   while (ni--){
       cin >> num;
       while (num--){
           cin >> element;
           mp[i].insert(element);
       }
       i++;
   }
   gg query, a, b;
   cin >> query;
   while (query--){
       cin >> a >> b;
       vector<gg>res1(mp[a].size() + mp[b].size());  // 交集
       vector<gg>res2(mp[a].size() + mp[b].size());   // 并集
       auto i = set_intersection(mp[a].begin(),mp[a].end(),mp[b].begin(),mp[b].end(),res1.begin());  //  注意返回值 和插入序列
       auto j = set_union(mp[a].begin(),mp[a].end(),mp[b].begin(),mp[b].end(),res2.begin());
       cout << fixed << setprecision(1) << distance(res1.begin(),i) * 100.0 / distance(res2.begin(),j) << "%\n";
   }
   return 0;
}
