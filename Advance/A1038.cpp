#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ni;
   cin>>ni;
   vector<string>vi(ni);
   for(auto& i : vi) cin>>i;
   sort(vi.begin(),vi.end(),[] (string a,string b){
       return  a + b < b + a ;
   });
   string res;
   for(auto& i : vi) res+=i;
   while(res.size() > 1 and res[0] == '0') res.erase(res.begin());   //  使用int版本 不能给单参数 不然 其之后都会被删除
   cout<<res;                                                        // 感觉int版本 单参数 都是指参数后面的整个串 而迭代器就是指一个值
   return 0;
}
