#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct Problem{
    gg score, cnum, rnum;
    string ans;
};
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   gg ni, mi, num;
   string s;
   char ch;
   cin>>ni>>mi;
   vector<Problem>problem(mi);
   for(auto& p : problem){
       s = "";
       cin>>p.score>>p.cnum>>p.rnum;
       for(gg i = 0;i < p.rnum;i++){
           cin>>ch;
           s += ch;
       }
       p.ans = s;
   }
   map<gg,gg>um, score;
   for(gg i =0;i<ni;i++){
       for(gg j =0;j<mi;j++){
           s = "";
           cin>>ch>>num;
           while(num--){
               cin>>ch;
               s += ch;
           }
           if(s == problem[j].ans) score[i] += problem[j].score;
           else um[j + 1]++;
           cin>>ch;
       }
   }
   for(gg i = 0;i<ni;i++) cout<<score[i]<<"\n";   //  每个人的分数都要输出
   if(um.empty()) cout<<"Too simple";
   else{
       gg res = -1;
       for(auto& i : um) {
           if(i.second > res){
               res = i.second;
           }
       }
       cout<<res;
       for(auto& i : um){
           if(i.second == res) cout<<" "<<i.first;
       }
   }
   return 0;
}
