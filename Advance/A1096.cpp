#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n;
   cin>>n;
   vector<gg>res;
   gg sqr = sqrt(n * 1.0);
   for(gg i =2;i<=sqr;i++){
       gg t = 1,j =i;
       vector<gg>tmp;
       while(1){
           t = t * j;
           if(n % t != 0) break;
           tmp.push_back(j);
           if(tmp.size() > res.size()) res = tmp;
           j++;
       }
   }
   if(res.size() == 0) cout<<1<<"\n"<<n;
   else{
       cout<<res.size()<<"\n";
       for(gg i=0;i<res.size();i++){
           if(i) cout<<"*";
           cout<<res[i];
       }
   }
   return 0;
}
