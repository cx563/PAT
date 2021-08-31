#include <bits/stdc++.h>
using namespace std;
using gg = long long;
vector<gg>res;
void build(vector<gg>& pre,vector<gg>& in,gg index,gg left,gg right){
    if(left > right) return ;
    gg i = find(in.begin(),in.end(),pre[index]) - in.begin();
    build(pre,in,index+1,left,i-1);
    build(pre,in,index+1+i-left,i+1,right);
    res.push_back(pre[index]);
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   string s;
   stack<gg>st;
   vector<gg>pre,in;
   gg n,tmp;
   cin>>n;
   for(gg i =0;i< 2 * n;i++){
       cin>>s;
       if(s == "Push"){
           cin>>tmp;
           st.push(tmp);
           pre.push_back(tmp);
       }else{
           in.push_back(st.top());
           st.pop();
       }
   }
   build(pre,in,0,0,in.size()-1);
   for(gg i=0;i<res.size();i++){
       if(i) cout<<" ";
       cout<<res[i];
   }
   return 0;
}
