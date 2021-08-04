#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n;
   cin>>n;
   gg A,B,C;
   int cont = 0;
   while(n--){
       cin>>A>>B>>C;
       gg res = A+B;
       if(A>0 and B >0 and res <0) cout<<"Case #"<<++cont<<": "<<"true"<<"\n";
       else if(A<0 and B<0 and res >= 0) cout<<"Case #"<<++cont<<": "<<"false"<<"\n";
       else if(res >C) cout<<"Case #"<<++cont<<": "<<"true"<<"\n";
       else cout<<"Case #"<<++cont<<": "<<"false"<<"\n";
   }
   return 0;
}
