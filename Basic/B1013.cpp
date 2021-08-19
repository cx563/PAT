#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg maxn = 105001;  //  一般定义这么大就可以了    这个数据就可以产生超过一万个素数了  素数大小 均小于 105001   1e5 + 5000
vector<gg>prime;   //  素数表
unordered_map<gg,bool>um;   // 素数判断
void Find_Prime(gg n){   //  n 是我最多要找的个数
    for(gg i = 2;i<maxn;i++){
        if(not um[i]) {   //  已经产生了一个素数
            prime.push_back(i);
            if(prime.size() == n) break;
            for(gg j = i +i ;j<maxn;j += i) um[j] = true;
        }
    }
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg a,b;
   cin>>a>>b;
   Find_Prime(b);
   gg aa =0;  //  格式控制
   for(gg i = a-1;i<= b-1;i++){
       if(aa) cout<<" ";
       cout<<prime[i];
       aa++;
       if(aa % 10 ==0){
           aa =0;
           cout<<"\n";
       }
   }
   return 0;
}
