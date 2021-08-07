#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct stu{
    gg nmuber;
    gg d_socre;
    gg c_score;
    gg id = 0;    // 由题意可知 我们要根据考生的类别进行排序 所以 考生必须有类别这个属性

    bool operator < (const stu& b) const{
        if(this->id != b.id) return this->id < b.id;
        else if(this->c_score +this->d_socre != b.c_score+b.d_socre) return (this->c_score+this->d_socre) > (b.c_score+b.d_socre);
        else if(this->d_socre != b.d_socre) return this->d_socre > b.d_socre;
        else return this->nmuber<b.nmuber;
    }
};
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ni,Li,Hi;
   cin>>ni>>Li>>Hi;
   stu tmpi;
   vector<stu>v;
   for(gg i=0;i<ni;i++){
       cin>>tmpi.nmuber>>tmpi.d_socre>>tmpi.c_score;
       if(tmpi.c_score >= Hi and (tmpi.d_socre >= Hi)) tmpi.id =1;
       else if(tmpi.d_socre >= Hi and(tmpi.c_score <Hi and tmpi.c_score >= Li)) tmpi.id =2;
       else if(tmpi.d_socre >= tmpi.c_score and tmpi.c_score >=Li and tmpi.d_socre <Hi) tmpi.id = 3;
       else tmpi.id =4;
       if(tmpi.c_score >= Li and tmpi.d_socre >= Li){
           v.push_back(tmpi);
       }
   }
   sort(v.begin(),v.end());
   cout<<v.size()<<"\n";
   for(auto i:v){
       cout<<i.nmuber<<" "<<i.d_socre<<" "<<i.c_score<<"\n";
   }
   return 0;
}
