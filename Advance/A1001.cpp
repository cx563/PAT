#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ai,bi;
   cin>>ai>>bi;
   gg res = ai + bi;
   res <0 ? cout<<"-",res = (-res) : res = res;
   string res1 = to_string(res);
   gg n = res1.size();
   gg i=0;
   if(n % 3 != 0) {    //   这里要注意 这个加逗号 是从后面向前加 故先把分不到一组的元素先输出
       cout<<res1.substr(0,n % 3);     // 还有是这里的参数 0是起始坐标   n%3 是字串的长度
       i = n % 3;
   }
   for(gg j =0;j<n/3;j++,i+=3){
       if(i) cout<<",";
       cout<<res1.substr(i,3);
   }
   return 0;
}
