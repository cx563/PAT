#include <bits/stdc++.h>
using namespace std;
using gg = long long;
string biao1[]{"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
string biao2[]{"Ge","Shi","Bai","Qian","Wan","Shi","Bai","Qian","Yi"};
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   string stri;
   cin>>stri;
   if(stri[0] == '-') {
      cout<<"Fu ";
      stri = stri.substr(1);
   }
   vector<string>res;
   reverse(stri.begin(),stri.end());
   gg len = stri.size();
   bool flag = false;
   for(gg i=0;i<len;i++){
      if((i == 5 or i==6 or i== 7) and stri[i] !='0') {
         flag = true;
         break;
      }
   }
   for(gg i=0;i<len;i++){
      if(i == 4 and (stri[i] == '0') and flag) res.push_back("Wan");
      if(i ==0 and (stri[i] != '0')) res.push_back(biao1[stri[i]-'0']);
      else if(i>0 and (stri[i] =='0') and res.size() and (res.back() != "ling") and (res.back() != "Wan")) res.push_back("ling"); 
      else if(i>0 and (stri[i] != '0')) res.push_back(biao1[stri[i]-'0']+" "+biao2[i]);
   }
   reverse(res.begin(),res.end());
   len = res.size();
   for(gg i=0;i<len;i++){
      if(i) cout<<" ";
      cout<<res[i];
   }
   if(stri == "0") cout<<"ling";   // '真'数据边界...
   return 0;
}
