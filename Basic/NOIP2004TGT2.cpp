#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   priority_queue<gg,vector<gg>,greater<gg>>q;   //  要将其逆序 也必须要指明底层容器
   gg n,t,ans =0;           //  map set 不用 map<gg,gg,greater<gg>>mp;   一般greater 在最后
   cin>>n;
   while(n--){
       cin>>t;
       q.push(t);
   }
   while(q.size() > 1){
       gg a = q.top();
       q.pop();
       gg b = q.top();
       q.pop();
       ans += a + b;
       q.push(a+b);
   }
   cout<<ans;
   return 0;
}
