
#include <bits/stdc++.h>
using namespace std;
using gg = long long;
char s[]{'J','Q','K'};
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   string ai,bi;
   cin>>ai>>bi;
   gg len = max(ai.size(),bi.size());
   while(ai.size() < len) ai = "0"+ai;   //  注意 这里 A和B的长度必须相同 若不同 要补前导0
   while(bi.size() < len) bi = "0"+bi; 
   for(gg i=bi.size()-1,ii = ai.size()-1,j=1;j<=len;i--,j++,ii--){
       if(j % 2 == 1) {
           gg temp= (bi[i]-'0'+(ai[ii]-'0')) % 13;
           temp > 9 ? bi[i] = s[temp-10] : bi[i] = temp +'0'; 
       }else{
           gg temp = bi[i] -ai[ii];
           temp <0 ?  bi[i] = temp+10+'0' : bi[i] = temp +'0';
       }
   }
   cout<<bi;
   return 0;
}
