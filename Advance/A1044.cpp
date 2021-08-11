#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ni, mi;
   cin>>ni>>mi;
   gg tmp;
   vector<gg>vi(ni+1); //  前缀和数组
   vi[0] = 0;
   for(gg i = 1;i <= ni;i++){
       cin>>tmp;
       vi[i] = vi[i-1] + tmp;
   }
   gg nearmost = 1e9;
   for(gg i=1;i <= ni;i++){    // 求出距离目标最近的和
        auto j = lower_bound(vi.begin()+i,vi.end(),mi + vi[i-1]);
        if(j != vi.end() and (*j - vi[i-1]) - mi < nearmost){
            nearmost = (*j - vi[i-1]) - mi;
        }
   }  
   for(gg i =1;i <= ni;i++){
       auto j = lower_bound(vi.begin(),vi.end(),mi + vi[i-1]);
       if(*j - vi[i-1] - mi == nearmost) {
           cout<< i <<"-"<<j - vi.begin() <<"\n";
       }
   }
   return 0;
}