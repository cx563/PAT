#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   map<gg,gg,greater<gg>>mp;   //  用greater  less 或 反迭代器 或 reverse(针对顺序容器) 可实现容器逆序
   gg ki,ni;
   cin>>ki;
   vector<gg>vi;
   mp[1]=2;
   while(ki--){
       cin>>ni;
       vi.push_back(ni);
       while(ni!=1){
           mp[ni]++;
           if(ni %2 ==0) ni/=2;
           else ni = (3*ni+1)/2;
       }
   }
   sort(vi.begin(),vi.end(),greater<gg>());
   gg res=0;
   for(auto i : vi){
       if(mp[i]==1){
           if(res) cout<<" ";
           cout<<i;
           res++;
       }
   }
   return 0;
}
