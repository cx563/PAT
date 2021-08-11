#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct cake{
    double sell;
    double left;
    double price;
};
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   double ni,di;
   cin>>ni>>di;
   vector<cake>vi(ni);
   for(auto& i : vi) cin>>i.left;
   for(auto& i : vi) {
       cin>>i.sell;
       i.price= i.sell/i.left;
   } 
   sort(vi.begin(),vi.end(),[] (const cake& a,const cake& b){
       return a.price > b.price;
   });
   double res =0;
   for(auto& i : vi){
       if(i.left >= di){
           res += di * i.price;
           break;
       }else{
           res += i.left * i.price;
           di -= i.left;
       }
       if(not di) break;
   }
   cout<<fixed<<setprecision(2)<<res;
   return 0;
}
