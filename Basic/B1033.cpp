#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   string s1,s2;
   getline(cin,s1);   //  第一个串可能为空串
   getline(cin,s2);
   unordered_map<char,bool>huai;
   for(auto i : s1){
       if(isalpha(i)) huai[i+32]=true;
       else huai[i] = true;
   }
   for(auto i :s2){
       if(isupper(i) and not huai['+'] and not huai[i+32]) cout<<i;
       else if(not isupper(i) and not huai[i]) cout<<i;  
   }
   cout<<"\n";
   return 0;
}
