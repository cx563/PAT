#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main(){
   ios::sync_with_stdio(false);
   cin.tie(0);
   string si, ai, bi;
   getline(cin,si);
   reverse(si.begin(),si.end());
   gg  c = 0, i = 0;
   vector<gg>a, b, res;
   getline(cin,ai);
   getline(cin,bi);
   for(gg i = ai.size()-1;i>=0;i--) a.push_back(ai[i] - '0');
   for(gg i = bi.size()-1;i>=0;i--) b.push_back(bi[i] - '0');
   for(i =0;i<a.size() or i < b.size();i++){
       gg t = (i >= a.size() ? 0 : a[i]) + (i >= b.size() ? 0 : b[i]) + c;
       res.push_back(t % (si[i] == '0' ? 10 : si[i] - '0'));
       c = t / (si[i] == '0' ? 10 : si[i] - '0');
   }
   while(c){
       res.push_back(c % (si[i] == '0' ? 10 : si[i] - '0'));
       c = c / (si[i] == '0' ? 10 : si[i] - '0');
       i++;
   }
   bool flag = false;
   reverse(res.begin(),res.end());
   for(auto i : res){
       if(i) flag = true;
       if(flag) cout<<i;
   }
   if(not flag) cout<<0;   //  可能有些结果是 00000 这种 。。。。
   return 0; 
}