#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct Fraction{
    gg up,down;
    Fraction(){
        up = 0 ;
        down = 1;
    }
}a,b;
gg gcd(gg a,gg b){
    return b == 0 ? a : gcd(b,a%b);
}
Fraction reduction(Fraction result){
    if(result.down < 0) {
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
Fraction add(Fraction f1,Fraction f2){
    Fraction result;
    result.up = f1.up * f2.down + f1.down * f2.up;
    result.down = f1.down * f2.down;
    return reduction(result);
}
Fraction minu(Fraction f1,Fraction f2){
    Fraction result;
    result.up = f1.up * f2.down - f2.up * f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}
Fraction multi(Fraction f1,Fraction f2){
    Fraction result;
    result.up = f1.up * f2.up;
    result.down = f1.down * f2.down;
    return reduction(result);
}
Fraction divide(Fraction f1,Fraction f2){
    Fraction result;
    result.up = f1.up * f2.down ;
    result.down = f1.down * f2.up;
    return reduction(result);
}
void showResult(Fraction r){
    r = reduction(r);
    if(r.up < 0) cout<<"(";
    if(r.down == 1) cout<<r.up;
    else if(abs(r.up) > r.down) cout<<r.up/r.down<<" "<<abs(r.up) % r.down<<"/"<<r.down;
    else{
        cout<<r.up<<"/"<<r.down;
    }
    if(r.up < 0) cout<<")";
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   char c;
   cin>>a.up>>c>>a.down>>b.up>>c>>b.down;
   showResult(a);
   cout<<" + ";
   showResult(b);
   cout<<" = ";
   showResult(add(a,b));
   cout<<"\n";
   showResult(a);
   cout<<" - ";
   showResult(b);
   cout<<" = ";
   showResult(minu(a,b));
   cout<<"\n";
   showResult(a);
   cout<<" * ";
   showResult(b);
   cout<<" = ";
   showResult(multi(a,b));
   cout<<"\n";
   showResult(a);
   cout<<" / ";
   showResult(b);
   cout<<" = ";
   if(b.up == 0) cout<<"Inf";
   else showResult(divide(a,b));
   cout<<"\n";
   return 0;
}
