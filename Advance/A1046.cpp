#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const int maxn = 1e5+10;
gg dist[maxn];
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n;
   cin>>n;
   int temp;
   //   v[i] 表示 节点v1 沿顺时针路径到节点vi+1 的距离
   for(int i = 1;i<= n;i++){
       cin>>temp;
       dist[i] = dist[i-1]+temp;
   }
   int m;
   cin>>m;
   int x,y;
   while(m--){
       cin>>x>>y;
       if(x > y) swap(x,y);
       cout<<min(dist[y-1]-dist[x-1],dist[n]-(dist[y-1]-dist[x-1]))<<"\n";
   }
   return 0;
}
