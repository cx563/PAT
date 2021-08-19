#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg num;
   cin>>num;
   gg left=0,right=0,now,res=0,a=1;
   while(num / a !=0){   //  模除 从最低位开始考虑 维护权重 方便获得左面 右面的值
       now = num / a % 10;
       left = num / (a * 10);
       right = num % a;
       if(now == 0) res += left * a;
       else if(now == 1) res += left * a + right +1;
       else res += (left + 1) * a;
       a *= 10;
   }
   cout<<res;
   return 0;
}
