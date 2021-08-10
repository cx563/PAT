#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   map<char,gg>mp;
   string si;
   getline(cin,si);
   for(auto i : si){
       if(isupper(i)) mp[i+32]++;
       else if(islower(i)) mp[i]++;

   }
   gg res=-1;
   for(auto i : mp) res = max(res,i.second);
   for(auto i : mp) {
       if(i.second == res) {
           cout<<i.first<<" "<<res;
           break;
       }
   }
   cout<<"\n";
   return 0;
}
