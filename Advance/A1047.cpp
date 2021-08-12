#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   unordered_map<gg,vector<string>>mp;
   gg snum, cnum, num, tmp;
   string name;
   cin >> snum >> cnum;
   while (snum--){
       cin >> name >> num;
       while (num--){
           cin >> tmp;
           mp[tmp].push_back(name);
       }
   }
   for (gg i=1;i <= cnum;i++){
       cout << i <<  " " << mp[i].size() << "\n";
       sort(mp[i].begin(),mp[i].end());
       for(auto i : mp[i]) {
           cout << i << "\n";
       }
   }
   return 0;
}
