#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ni,pi;
   cin>>ni>>pi;
   vector<gg>vi(ni);
   for(auto& i : vi) cin>>i;
   sort(vi.begin(),vi.end());
   gg res=-1;
   for(auto i = vi.begin(); i !=vi.end();i++){   //  枚举左端点 用二分找右端点
      auto j = upper_bound(vi.begin(),vi.end(),*i * pi);
      if(distance(i,j) > res) res = distance(i,j);   //   刚好是左闭右开的区间
   }
   cout<<res;
   return 0;
}
