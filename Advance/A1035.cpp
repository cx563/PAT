#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n,res =0;
   cin>>n;
   vector<gg>res2;
   vector<array<string,2>>v(n);
   for(gg i=0;i<n;i++){
       cin>>v[i][0]>>v[i][1];
       gg temp = v[i][1].size();
       bool flag = false;
       for(gg ii=0;ii<temp;ii++){
           if(v[i][1][ii] == '1'){
               v[i][1][ii] = '@';
               if (!flag) {
                   res2.push_back(i);
                   res++;
                }
               flag = true;
           }else if(v[i][1][ii] == '0'){
               v[i][1][ii] = '%';
               if (!flag) {
                   res2.push_back(i);
                   res++;
                }
               flag = true;
           }else if(v[i][1][ii] == 'l'){
               v[i][1][ii] = 'L';
               if (!flag) {
                   res2.push_back(i);
                   res++;
                }
               flag = true;
           }else if(v[i][1][ii] == 'O'){
               v[i][1][ii] = 'o';
               if (!flag) {
                   res2.push_back(i);
                   res++;
                }
               flag = true;
           }
       }
   }
   if(!res) n>1 ? cout<<"There are "<<n<<" accounts and no account is modified" : cout<<"There is 1 account and no account is modified";
   else {
       cout<<res<<"\n";
       for(auto i : res2){
           cout<<v[i][0]<<" "<<v[i][1]<<"\n";
       }
   }
   return 0;
}