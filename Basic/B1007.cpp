#include <bits/stdc++.h>
using namespace std;
using gg = long long;
bool isPrime(gg n){
    if(n == 1) return false;
    gg sqr = sqrt(n);
    for(gg i =2 ;i <= sqr;i++){
        if(n % i == 0) return false;
    }
    return true;
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n;
   gg res =0;
   cin>>n;
   for(gg i=3;i+2 <= n;i += 2){   //  i 一定至少是奇数
       if(isPrime(i) and isPrime(i + 2)) res++;
   }
   cout<<res;
   return 0;
}