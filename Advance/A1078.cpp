#include <bits/stdc++.h>
using namespace std;
using gg = long long;
unordered_map<gg,bool>um; //   标记 哈希表这位有无被占用
bool isPrime(gg n){
    if(n <= 1) return false;
    gg sqr = sqrt(n * 1.0);
    for(gg i=2;i<=sqr;i++){
        if(n % i == 0) return false;
    }
    return true;
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n,TSize,a;
   cin>>TSize>>n;
   while(not isPrime(TSize)) TSize++;
   for(gg i=0;i<n;i++){
       cin>>a;
       gg pos = a % TSize;
       if(not um[pos]) {
           um[pos] = true;
           if(i) cout<<" ";
           cout<<pos;
       }else{
           gg step;
           for(step = 1;step < TSize;step++){
               pos = (a + step * step) % TSize;
               if(not um[pos]){
                   um[pos] = true;
                   if(i) cout<<" ";
                   cout<<pos;
                   break;
               }
           }
           if(step >= TSize) {
               if(i) cout<<" ";
               cout<<"-";
           }
       }
   }
   return 0;
}
