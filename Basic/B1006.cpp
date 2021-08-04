#include <bits/stdc++.h>
using namespace std;
using gg = long long;
void f1(gg t){
    for(gg i=1;i<=t;i++) cout<<i;
}
void f2(gg t){
    for(gg i=0;i<t;i++) cout<<"S";
}
void f3(gg t){
    for(gg i =0;i<t;i++) cout<<"B";
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   string stri;
   cin>>stri;
   if(stri.size() == 1) f1(stri[0] - '0');
   else if(stri.size() == 2) {
       f2(stri[0]- '0');
       f1(stri[1] -'0');
   }else{
       f3(stri[0]-'0');
       f2(stri[1]-'0');
       f1(stri[2]-'0');
   }
   return 0;
}
