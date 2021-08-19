#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct Fraction{
    gg up,down;
    Fraction(){
        up = 0;
        down = 1;
    }
};
gg gcd(gg a,gg b){  //   最大公约数
    if(b == 0) return a;
    else return gcd(b,a%b);
}
Fraction reduction(Fraction result){
    if(result.down < 0){
        result.down = - result.down;
        result.up = - result.up;
    }
    if(result.up == 0) result.down = 1;
    else{
        gg d = gcd(abs(result.up),result.down);
        result.up /= d;
        result.down /= d;
    }
    return result;
}
Fraction add(Fraction a,Fraction b){
    Fraction result;
    result.up = a.up * b.down + b.up * a.down;
    result.down = a.down * b.down;
    return reduction(result);   //   每步均要化简
}
void showResult(Fraction r){
    if(r.down == 1) cout<<r.up;  //  0 的情况也包含了进去
    else if(abs(r.up) > abs(r.down)) cout<<r.up / r.down <<" "<<abs(r.up) % r.down<<"/"<<r.down;
    else cout<<r.up<<"/"<<r.down;
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n;
   char c;
   cin>>n;
   Fraction sum,tmp;
   while(n--){
       cin>>tmp.up>>c>>tmp.down;
       sum = add(sum,tmp);
   }
   showResult(sum);
   return 0;
}
