#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct stu{
    string id;
    string name;
    gg score;
};
bool cmp1(stu a,stu b){
    return a.id<b.id;
}
bool cmp2(stu a,stu b){
    if(a.name != b.name) return a.name<b.name;
    else return a.id<b.id;
}
bool cmp3(stu a,stu b){
    if(a.score != b.score) return a.score<b.score;
    else a.id<b.id;
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   stu tmpi;
   vector<stu>v;
   gg ni,ci;
   cin>>ni>>ci;
   while(ni--){
       cin>>tmpi.id>>tmpi.name>>tmpi.score;
       v.push_back(tmpi);
   } 
   if(ci==1) sort(v.begin(),v.end(),cmp1);
   else if(ci ==2) sort(v.begin(),v.end(),cmp2);
   else sort(v.begin(),v.end(),cmp3);
   for(auto i:v){
       cout<<i.id<<" "<<i.name<<i.score<<"\n";
   }
   return 0;
}
