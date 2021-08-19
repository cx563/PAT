#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg maxn = 1e5 + 5000;
unordered_map<gg,bool>um;
vector<gg>prime;
void Find_Prime(){
    for(gg i=2;i<maxn;i++){
        if(not um[i]){
            prime.push_back(i);
            for(gg j = i+ i;j<maxn;j += i) um[j] = true;
        }
    }
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   Find_Prime();
   gg n;
   cin>>n;
   vector<array<gg,2>>res;  //  第一个数是值 第二个数是 指数
   if(n == 1) cout<<"1=1";
   else{
       cout<<n<<"=";
       for(auto i : prime){
           if(n % i ==0){
               res.push_back({i,0});
               while(n % i ==0){
                   res.back()[1]++;
                   n /= i;
               }
           } 
          if(n == 1) break;   //  整除
       }
       if(n != 1) res.push_back({n,1});
       for(gg i =0;i<res.size();i++){
           if(i) cout<<"*";
           cout<<res[i][0];
           if(res[i][1] > 1) cout<<"^"<<res[i][1];
       }
   }
}


