#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n,m,a,b,k,num;
   cin>>n>>m;
   vector<vector<bool>>graph(n + 1,vector<bool>(n + 1,false));
   while(m--){
       cin>>a>>b;
       graph[a][b] = graph[b][a] = true;
   }
   cin>>k;
   while(k--){
       bool ans = true;
       cin>>num;
       vector<gg>v(num);
       unordered_set<gg>us;
       for(auto& i : v){
           cin>>i;
           us.insert(i);
       }
       if(num != n + 1 or v[0] != v.back() or us.size() != n) ans = false;
       for(gg i =0;i<v.size()-1;i++){
           if(not graph[v[i]][v[i+1]]) ans = false;
       }
       cout<<(ans ? "YES\n" : "NO\n");
   }
   return 0;
}
