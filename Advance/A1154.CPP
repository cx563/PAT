#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n,m,k;
   cin>>n>>m;
   vector<array<gg,2>>edges(m);
   for(auto& e : edges) cin>>e[0]>>e[1];
   cin>>k;
   while(k--){
       vector<gg>color(n);
       unordered_set<gg>us;  //  set的排序功能没有了 但去重功能还在
       for(auto& i : color){
           cin>>i;
           us.insert(i);
       }
       for(auto& i : edges){
           if(color[i[0]] == color[i[1]]) {
               cout<<"No\n";
               goto loop;
           }
       }
       cout<<us.size()<<"-coloring\n";
       loop:;
   }
   return 0;
}
