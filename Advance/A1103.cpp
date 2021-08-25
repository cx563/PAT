#include <bits/stdc++.h>
using namespace std;
using gg = long long;
gg n,k,p,rsum = -1;
vector<gg>fac,res,tmp;
void init(){
    gg i = 0,tmp = 0;
    while(tmp <= n){
        fac.push_back(tmp);
        tmp = pow(++i,p);
    }
}
void DFS(gg index,gg nowsum,gg fsum,gg nowk){
    if(index == k and nowsum == n){   //   先判断边界 优化解
        if(fsum > rsum){
            rsum =fsum;
            res = tmp;
        }
        return;
    }
    if(index >= k or nowsum >= n or nowk < 1) return;   //   剪枝
    tmp.push_back(nowk);
    DFS(index+1,nowsum + fac[nowk],fsum+nowk,nowk);   // 扩展 
    tmp.pop_back();
    DFS(index,nowsum,fsum,nowk-1);

}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>k>>p;
   init();
   DFS(0,0,0,fac.size()-1);
   if(not res.size()) cout<<"Impossible";
   else{
       cout<<n<<" = ";
       for(gg i=0;i<res.size();i++){
           if(i) cout<<" + ";
           cout<<res[i]<<"^"<<p;
       }
   }
   return 0;
}
