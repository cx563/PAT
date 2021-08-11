#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct st{
    double dist,price;
};
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   double capi,di,davgi,ni;
   cin>>capi>>di>>davgi>>ni;
   vector<st>vi(ni);
   for(auto& i : vi) cin>>i.price>>i.dist;
   vi.push_back({di,0.0});  //  将终点当中一个加油站 单价为0 我们会对距离进行排序 我们一定选择第一个油价小于自身油价的
   sort(vi.begin(),vi.end(),[] (const st& a,const st& b){
       return tie(a.dist) < tie(b.dist);
   }) ;
   if(vi[0].dist !=0) {
       cout<<"The maximum travel distance = 0.00\n";
   }else{
       double MAX = capi * davgi;
       double res =0.0;
       double nowTank =0.0;
       gg i,j;
       for(i=0;i<ni;){
           j = i+1;
           double dis = 1e8;
           gg jj =-1;
           while(j <= ni and vi[j].dist - vi[i].dist <= MAX){
               if(vi[j].price < vi[i].price){
                   jj = j;
                   break;
               }
               if(vi[j].price < dis){
                   dis = vi[j].price;
                   jj =j;
               }
               j++;
           }
           if(jj == -1) break;
           double distance = vi[jj].dist - vi[i].dist;
           if(vi[jj].price < vi[i].price){
               if(nowTank * davgi >= distance){
                  nowTank -= distance / davgi;
               }else{
                   res += (distance / davgi - nowTank) * vi[i].price;
                   nowTank =0; 
               }
           }else{
               res += (capi - nowTank) * vi[i].price;
               nowTank = capi -distance/davgi;
           }
           i = jj;
       }
       if(i == ni) cout<<fixed<<setprecision(2)<<res<<"\n";
       else cout<<"The maximum travel distance = "<<fixed<<setprecision(2)<<vi[i].dist + MAX;
   }
   return 0;
}
