#include <bits/stdc++.h>
using namespace std;
using gg = long long;
bool isPrime(gg n){
    if(n <= 1) return false;
    gg sqr = sqrt(n);
    for(gg i=2;i<=sqr;i++){
        if(n % i ==0){
            return false;
        }
    }
    return true;
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n,d;
   while(cin>>n and n >= 0){
       cin>>d;
       if(not isPrime(n)) cout<<"No\n";
       else{
           vector<gg>res;   // 已经在这个进制的基础上逆序
           while(n !=0){
               res.push_back(n % d);
               n /= d;
           }
           gg r =0;
           for(auto i : res) r = r * d + i;    //   要乘自己的进制d
           if(isPrime(r)) cout<<"Yes\n";
           else cout<<"No\n";
       }
   }
   return 0;
}
