#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n,m,k,t,a;
   cin>>n>>m;
   vector<array<gg,2>>edge(m);
   for(auto& e : edge) cin>>e[0]>>e[1];
   cin>>k;
   while(k--){
       unordered_set<gg>us;
       cin>>t;
       while(t--){
           cin>>a;
           us.insert(a);
       }
       for(auto& e : edge){
           if(not us.count(e[0]) and not us.count(e[1])){
               cout<<"No\n";
               goto loop;
           }
       }
       cout<<"Yes\n";
       loop:;
   }
   return 0;
}
