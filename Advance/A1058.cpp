#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   vector<gg> ai(3),bi(3),res(3);
   char c;
   cin>>ai[0]>>c>>ai[1]>>c>>ai[2];
   cin>>bi[0]>>c>>bi[1]>>c>>bi[2];
   gg carry =0;
   res[2] = (ai[2]+bi[2]+ carry) % 29;
   carry = (ai[2]+bi[2]+ carry) / 29;
   res[1] = (ai[1]+bi[1]+ carry) % 17;
   carry = (ai[1]+bi[1]+ carry) / 17;
   res[0] = ai[0]+bi[0]+carry;
   cout<<res[0]<<c<<res[1]<<c<<res[2];
   return 0;
}
