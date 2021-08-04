#include <bits/stdc++.h>
using namespace std;
using gg = long long;
array<string,2> res1,res2;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg fscore = -1,mscore = 101,scorei = 0;
   string namei,mi,idi;
   int ni;
   cin>>ni;
   while(ni--){
       cin>>namei>>mi>>idi>>scorei;
       if(mi == "F") {
           if(scorei > fscore){
               fscore = scorei;
               res1[0] = namei;
               res1[1] = idi;
           }
       }else {
            if(scorei < mscore){
                mscore = scorei;
                res2[0] = namei;
                res2[1] = idi;
            }
       }
   }
   res1[0] == "" ? cout<<"Absent"<<"\n" : cout<<res1[0]<<" "<<res1[1]<<"\n";
   res2[0] == "" ? cout<<"Absent"<<"\n" : cout<<res2[0]<<" "<<res2[1]<<"\n";
   res1[0] =="" or res2[0] == "" ? cout<<"NA": cout<<fscore- mscore;
   return 0;
}
