#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ni;
   char c;
   cin>>ni>>c;
   gg res =0;
   gg x = sqrt(2.0 * (1+ ni)) -1;
   if (x % 2 ==0) x-=1;   // 判定最高层输出为奇数个c
   for(gg i = x;i>= 1;i-=2){
       for(gg j = 0;j<(x - i)/2;j++) cout<<" ";
       for(gg j=0;j<i;j++){
           cout<<c;
           res++;
       }
       cout<<"\n";
   }
   for(gg i = 3;i<= x;i+=2){
       for(gg j = 0;j<(x - i)/2;j++) cout<<" ";
       for(gg j=0;j<i;j++){
           cout<<c;
           res++;
       }
       cout<<"\n";
   }
   cout<< ni - res;
   return 0;
}
