#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   vector<gg>num;    //   存储大整数   逆序存放
   string s;
   cin>>s;
   for(gg i= s.size() - 1;i>=0;i--) num.push_back(s[i] - '0');
   vector<gg>re;  //   商
   gg r =0,b;  //  余数
   cin>>b;
   for(gg i=num.size() -1;i>=0;i--){
       r = r * 10 +num[i];
       if(r < b) re.push_back(0);
       else{
           re.push_back(r / b);
           r = r % b;
       }
   }
   while(re.size() > 1 and re[0] == 0) re.erase(re.begin());
   for(auto i : re) cout<<i;
   cout<<" "<<r ;
   return 0;
}
