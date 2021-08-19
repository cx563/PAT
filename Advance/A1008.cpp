#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n;
   cin>>n;
   gg res =0,now =0,tmp;
   while(n--){
       cin>>tmp;
       if(tmp > now) res += (tmp - now) * 6;
       else res += (now - tmp) * 4;
       res += 5;
       now = tmp;
   }
   cout<<res;
   return 0;
}
