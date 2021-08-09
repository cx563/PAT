#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct stu{
    gg ge;
    gg gi;
    gg frage;
    gg rank;
    gg id;
    array<gg,5> choice;
    bool operator<(const stu& b) const{
        if(this->frage != b.frage) return this->frage > b.frage;
        else if(this->ge!= b.ge) return this->ge > b.ge;
        else return false;    //  这里重载的是this小于b的规则，即this在b左边的规则  若在优先队列中，则是this的优先级小于b的规则  
                              //  注意这里 前面写的是小于的规则，如果没有相应的判定条件 默认应该返回false  即this是不小于b的
    }
};

struct sch{
    gg id;
    gg qutoa;
    vector<gg>res;
};

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ni,mi,ki;
   cin>>ni>>mi>>ki;
   vector<stu>stui(ni);
   vector<sch>schi(mi);
   for(gg i=0;i<mi;i++){
       schi[i].id =i;
       cin>>schi[i].qutoa;
   }
   for(gg i=0;i<ni;i++){
       stui[i].id=i;
       cin>>stui[i].ge>>stui[i].gi;
       for(gg j=0;j<ki;j++) cin>>stui[i].choice[j];
       stui[i].frage= stui[i].ge+stui[i].gi;
   }
   sort(stui.begin(),stui.end());
   stui[0].rank=1;
   for(gg i=1;i<ni;i++){
       if(stui[i].frage == stui[i-1].frage and stui[i].ge == stui[i-1].ge) stui[i].rank = stui[i-1].rank;
       else stui[i].rank = i+1;
   }
   for(gg i=0;i<ni;i++){
       for(gg j=0;j<ki;j++){
           sch& t = schi[stui[i].choice[j]];    //  注意这里的引用类型
           if(t.res.size() < t.qutoa) {
               t.res.push_back(i);
               break;
           }else if(t.res.size() >= t.qutoa and stui[i].rank == stui[t.res.back()].rank){
               t.res.push_back(i);
               break;
           }
       }
   }
   vector<gg>res;
   for(gg i=0;i<mi;i++){
       if(schi[i].res.size() == 0) cout<<"\n";
       else {
           for(auto i : schi[i].res){
               res.push_back(stui[i].id);
           }
           sort(res.begin(),res.end());
           int len = res.size();
           for(gg j=0;j<len;j++){
               if(j) cout<<" ";
               cout<<res[j];
           }
           res.clear();
           cout<<"\n";
       }
   }
   return 0;
}
