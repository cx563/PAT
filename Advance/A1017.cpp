#include <bits/stdc++.h>
using namespace std;
using gg = long long;
using agg2 = array<gg,2>;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ni, ki;
   cin>>ni>>ki;
   gg startTime = 8 * 60 * 60, endTime = 17 * 60 * 60;
   priority_queue<gg,vector<gg>,greater<gg>>window;
   priority_queue<agg2,vector<agg2>,greater<agg2>>customer;
   for(gg i =0;i<ki;i++) window.push(startTime);
   while(ni--){
       gg h, m, s, p;
       char c;
       cin>>h>>c>>m>>c>>s>>p;
       gg arriveTime = h * 60 * 60 + m * 60 + s;
       if(arriveTime > endTime) continue;
       customer.push({arriveTime,p * 60});
   }
   gg time = 0, num = customer.size();
   while(not customer.empty()){
       auto c = customer.top();
       customer.pop();
       gg t = window.top();
       window.pop();
       if(t > c[0]){
           time += t - c[0];
       }
       window.push(max(t,c[0]) + c[1]);  //  该窗口下一次空闲时间
   }
   cout<<fixed<<setprecision(1)<<time / 60.0 / num;
   return 0;
}
