#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   // 直接两个两个 读入处理 不可能覆盖
   int ci,ei;
   int cont =0;
   while(cin>>ci>>ei){
       if(ei == 0) ;
       else {
           if(cont) cout<<" ";
           cont ++;
           cout<<ci * ei <<" "<<ei -1;
       }
   }
   if(cont == 0) cout<<"0 0";
   return 0;
}
