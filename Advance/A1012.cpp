#include <bits/stdc++.h>
using namespace std;
using gg = long long;
unordered_map<gg,array<gg,4>>mp;
char biao[]{'A','C','M','E'};
struct stu{
    gg id;
    gg avg;
    gg c;
    gg m;
    gg e;
};
bool cmp1(stu a,stu b){
    return a.avg > b.avg;
}
bool cmp2(stu a,stu b){
    return a.c>b.c;
} 
bool cmp3(stu a,stu b){
    return a.m>b.m;
}
bool cmp4(stu a,stu b){
    return a.e>b.e;
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ni,mi;
   cin>>ni>>mi;
   stu tmpi;
   vector<stu>v;
   while(ni--){
       cin>>tmpi.id>>tmpi.c>>tmpi.m>>tmpi.e;
       tmpi.avg=(tmpi.c+tmpi.m+tmpi.e)/3;
       v.push_back(tmpi);
   }
   sort(v.begin(),v.end(),cmp1);
   gg len = v.size();
   mp[v[0].id][0]=1;
   for(gg i=1;i<len;i++){
       if(v[i].avg==v[i-1].avg ) mp[v[i].id][0]= mp[v[i-1].id][0];
       else  mp[v[i].id][0] = i+1;
   }
   sort(v.begin(),v.end(),cmp2);
   mp[v[0].id][1]=1;
   for(gg i=1;i<len;i++){
       if(v[i].c==v[i-1].c ) mp[v[i].id][1]= mp[v[i-1].id][1];
       else  mp[v[i].id][1] = i+1;
   }
   sort(v.begin(),v.end(),cmp3);
   mp[v[0].id][2]=1;
   for(gg i=1;i<len;i++){
       if(v[i].m==v[i-1].m ) mp[v[i].id][2]= mp[v[i-1].id][2];
       else  mp[v[i].id][2] = i+1;
   }
   sort(v.begin(),v.end(),cmp4);
   mp[v[0].id][3]=1;
   for(gg i=1;i<len;i++){
       if(v[i].e==v[i-1].e ) mp[v[i].id][3]= mp[v[i-1].id][3];
       else  mp[v[i].id][3] = i+1;
   }
   gg query;
   char res;
   gg res2=INT_MAX;
   while(mi--){
       cin>>query;
       if(mp.count(query)==0) cout<<"N/A"<<"\n";
       else {
           for(gg i=0;i<4;i++){
               if(mp[query][i]<res2){
                   res2 = mp[query][i];
                   res= biao[i];
               }
           }
           cout<<res2<<" "<<res<<"\n";
       }
       res2 =INT_MAX;
   }
   return 0;
}