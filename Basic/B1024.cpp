#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   string stri;
   cin>>stri;
   if(stri[0] == '-') cout<<"-";
   gg pos = stri.find('E');
   string num = stri.substr(1,pos-1);  // 数字部分
   gg exp = stoi(stri.substr(pos+1));  // 指数部分
   if(exp < 0){
       cout<<"0.";
       for(gg i=0;i<exp-1;i++) cout<<"0";
       cout<<num[0]<<num.substr(2);
   }else if(exp > 0){
       if(exp < num.size()-2){
           cout<<num[0]<<num.substr(2,exp)<<"."<<num.substr(2+exp);
       }else if(exp > num.size() -2){
           cout<<num[0]<<num.substr(2);
           gg len = num.size();
           for(gg i=0;i<exp-(len -2 );i++) cout<<"0";
       }else {
           cout<<num[0]<<num.substr(2);
       }
   }else cout<<num;
   return 0;
}
