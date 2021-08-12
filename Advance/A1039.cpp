#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg query, cnum;
   cin >> query >> cnum;
   gg index, num;
   string name;
   unordered_map<string,vector<gg>>mp;
   while (cnum--){
       cin >> index >> num;
       while (num--){
           cin>>name;
           mp[name].push_back(index);
       }
   }
   while (query--){
       cin >> name;
       cout << name << " " << mp[name].size();
       sort(mp[name].begin(),mp[name].end());
       for (auto& i : mp[name]) {
           cout << " " << i;
       }
       cout << "\n";
   }
   return 0;
}
