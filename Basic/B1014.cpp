#include <bits/stdc++.h>
using namespace std;
using gg = long long;
string biao[]{"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   vector<string>v(4);
   for(gg i=0;i<4;i++) cin>>v[i];
   gg len = min(v[0].size(),v[1].size());
   gg i;
   for(i=0;i<len;i++)
       if(v[0][i] == v[1][i] and (v[0][i] >='A' and v[0][i] <= 'G') ) break;
    cout<<biao[v[0][i]-'A']<<" ";
    for(i++;i<len;i++)
        if(v[0][i] == v[1][i] and (isdigit(v[0][i]) or (v[0][i] >= 'A' and v[0][i] <='N'))) break;
    cout<<setfill('0');
    cout<<setw(2)<<(isdigit(v[0][i]) ? v[0][i] - '0' : v[0][i] - 'A' +10)<<":";
    len = min(v[2].size(),v[3].size());
    for(i =0;i<len;i++)
        if(v[2][i] == v[3][i] and isalpha(v[2][i])) break;
    cout<<setw(2)<<i;
   return 0;
}
