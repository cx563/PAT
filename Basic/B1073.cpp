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
   gg ni, mi, num;
   cin>>ni>>mi;
   vector<Problem>problem(mi);
   string s;
   char ch;
   for(auto& i : problem){
       s = "";
       cin>>i.score>>i.cnum>>i.rnum;
       for(gg j =0;j<i.rnum;j++){
            cin>>ch;
            s += ch;
       }
       i.ans = s;
   }
   map<pair<gg,char>,gg>res;
   map<gg,double>score;
   for(gg i =0;i<ni;i++){
       for(gg j =0;j<mi;j++){
           s = "";
           cin>>ch>>num;
           while(num--){
               cin>>ch;
               s += ch;
           }
           if(s == problem[j].ans) score[i] += problem[j].score;
           else{
               num = count_if(s.begin(),s.end(),[&problem, j](char ch){
                   return (find(problem[j].ans.begin(),problem[j].ans.end(),ch) == problem[j].ans.end());
               });
               if(num == 0) score[i] += problem[j].score / 2.0;  //  这逻辑有毒
                for(auto& c : s){
                    if(find(problem[j].ans.begin(),problem[j].ans.end(),c) == problem[j].ans.end()){
                        res[{j+1, c}]++;
                    }
                }
                for(auto& c : problem[j].ans){
                    if(find(s.begin(),s.end(),c) == s.end()){
                        res[{j+1, c}]++;
                    }
                }
           } 
           cin>>ch;
       }
   }
   for(gg i=0;i<ni;i++) cout<<fixed<<setprecision(1)<<score[i]<<"\n";
   if(res.size() == 0) cout<<"Too simple";
   else{
       gg num = -1;
       for(auto& i : res){
           if(i.second > num) num = i.second;
       }
       for(auto& i : res){
           if(i.second == num){
               cout<<i.second<<" "<<i.first.first<<"-"<<i.first.second<<"\n";
           }
       }
   }
   return 0;
}
