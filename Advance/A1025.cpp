#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct stu{
    string id;
    gg score;
    gg num_local;
    gg num_all;
    gg test_num;
    bool operator<(const stu& b) const{
        if(this->score != b.score) return this->score>b.score;
        else return this->id<b.id;
    }
};
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ni,mi;
   cin>>ni;
   stu tmpi;
   vector<stu>v;
   for(gg i=1;i<=ni;i++){
       cin>>mi;
       for(gg j=0;j<mi;j++){
           cin>>tmpi.id>>tmpi.score;
           tmpi.test_num=i;
           v.push_back(tmpi);
       }
       gg len = v.size();   //   一定要注意这里的区间是 [v.size()-mi,v.size())
       sort(v.begin()+(len-mi),v.end());
       v[len-mi].num_local=1;
       for(gg j=len-mi+1;j<len;j++){
           if(v[j].score==v[j-1].score) v[j].num_local=v[j-1].num_local;
           else v[j].num_local=j-(len-mi)+1;
       }
   } 
    sort(v.begin(),v.end());
    v[0].num_all=1;
    gg len = v.size();
    for(gg j=1;j<len;j++){
        if(v[j].score==v[j-1].score) v[j].num_all=v[j-1].num_all;
        else v[j].num_all=j+1;
    }
    cout<<v.size()<<"\n";
    for(auto i:v){
        cout<<i.id<<" "<<i.num_all<<" "<<i.test_num<<" "<<i.num_local<<"\n";
    }  
   return 0;
}
