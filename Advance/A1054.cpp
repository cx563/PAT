#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   unordered_map<gg,gg>mp;
   gg mi,ni,img;
   cin >>mi >>ni;
   for(gg i=0;i<ni;i++){
       for(gg j=0;j<mi;j++){
           cin >> img;
           mp[img]++;
       }
   }
   for (auto i : mp) {
       if (i.second > (mi * ni) /2) {
           cout << i.first;
           break;
       }
   }
   return 0;
}
