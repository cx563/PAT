#include <bits/stdc++.h>
using namespace std;
using gg = long long;
vector<gg>res;
void search(vector<gg>& pre,gg index,gg left,gg right,bool mirror){
    if(left > right) return;
    gg i = find_if(pre.begin()+left+1,pre.begin()+right+1,[pre,index,mirror](gg a){  //  左闭右开区间 右子树起点至少是 left + 1
        return mirror? a < pre[index] : a >= pre[index];   //  左子树不需要检测 一定满足 find_if
    }) - pre.begin();
    if(any_of(pre.begin()+i,pre.begin()+right+1,[pre,index,mirror](gg a){
        return mirror ? a >= pre[index] : a < pre[index];
    })){
        return;
    }
    search(pre,index+1,index+1,i-1,mirror);
    search(pre,i,i,right,mirror);
    res.push_back(pre[index]);
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n;
   cin>>n;
   vector<gg>pre(n);
   for(auto& i : pre) cin>>i;
   search(pre,0,0,pre.size()-1,false);
   if(res.size() == n){
       cout<<"YES\n";
       for(gg i=0;i<n;i++){
           if(i) cout<<" ";
           cout<<res[i];
       }
   }else{
       res.clear();
       search(pre,0,0,pre.size()-1,true);
       if(res.size() == n){
           cout<<"YES\n";
           for(gg i=0;i<n;i++){
           if(i) cout<<" ";
           cout<<res[i];
           }
       }else{
           cout<<"NO";
       }
   }
   return 0;
}
