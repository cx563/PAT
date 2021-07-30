#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n,m;
   cin>>n>>m;
   vector<int> v(n);
   for(int i=0;i<n;i++){
       cin>>v[i];
   }
   m= m % n ; 
   /*for(int i=n-m;i<=n-1;i++) {
       if(i != n-m) cout<<" ";
       cout<<v[i];
   }
   if(m) cout<<" ";
   for(int i=0;i<=n-m-1;i++){
       if(i) cout<<" ";
       cout<<v[i];
   }*/
   // 考研数据结构题目
   reverse(v.begin()+n-m,v.end());
   reverse(v.begin(),v.begin()+n-m); // 这里参数应该是n-m 应为其右侧取不到
   reverse(v.begin(),v.end());
   for(int i=0;i<n;i++){
       if(i) cout<<" ";
       cout<<v[i];
   }
   return 0;
}
