#include <bits/stdc++.h>
using namespace std;
using gg = long long;
char s[3] = {'w','T','L'};
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   double ans = 1.0,tmp,ai;
   gg idx;
   for(gg i = 0;i<3;i++){
       tmp = 0.0;
       for(gg j=0;j<3;j++){
           cin>>ai;
           if(ai>tmp){
               tmp = ai;
               idx = j;
           }
       }
       ans *= tmp;
       cout<<s[idx]<<" ";
   }
   cout<<fixed<<setprecision(2)<<(ans* 0.65 - 1) * 2;
   return 0;
}
