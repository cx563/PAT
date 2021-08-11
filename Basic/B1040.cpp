#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   string s;
   cin>>s;
   unordered_map<gg,gg>left;
   unordered_map<gg,gg>right;
   for(gg i=0;i < s.size();i++){
       if(s[i] == 'P') left[i] = left[i-1] + 1;   //  前缀和
       else left[i] = left[i-1];
   }
   for(gg i=s.size() - 1;i >= 0;i--){
       if(s[i] == 'T') right[i] = right[i+1] + 1;   //  后缀和
       else right[i] = right[i+1];
   }
   gg res=0;
   for(gg i =0;i < s.size();i++){
       if(s[i] == 'A') res += left[i] * right[i];
   }
   cout<<res %  1000000007 ;
   return 0;
}
