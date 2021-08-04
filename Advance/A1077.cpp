#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   int ni;
   cin>>ni;
   vector<string>vi(ni);
   gg mlen=268;
   cin.get();   // 注意这里的面行读入 下面输入数字 留有一个空格
   for(gg i=0;i<ni;i++){
       getline(cin,vi[i]);
       if(vi[i].size()<mlen) mlen = vi[i].size();
   }
   gg i;
   for(i =1;i<=mlen;i++){
       for(gg j=0;j<ni-1;j++){
           if(vi[j][vi[j].size()-i] != vi[j+1][vi[j+1].size()-i] ) goto loop;
       }
   }
   loop:;
   i ==1 ? cout<<"nai" : cout<<vi[0].substr(vi[0].size()-i+1,i-1);   // 注意 这里的i -1   i位置不是公共后缀位置
   return 0;
}
