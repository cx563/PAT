#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   string s;
   cin>>s;
   while(s.size() < 4) s =s + '0';    //  刚进来时就要加位
   auto tmp = count_if(s.begin(),s.end(),[s](char c){   //  一定要严谨 仔细考虑
       return c != s[0];
   });
   if(not tmp){
       cout<<s<<" - "<<s<<" = 0000";
       goto loop;
   }
   if(s == "6174") cout<<"7641 - 1467 = 6174";
   while(s != "6174"){
       sort(s.begin(),s.end(),greater<char>());
       gg a = stoll(s);
       sort(s.begin(),s.end());
       gg b = stoll(s);
       cout<<setfill('0');
       cout<<setw(4)<<a<<" - "<<setw(4)<<b<<" = "<<setw(4)<<a - b<<"\n";
       s= to_string(a-b);
       while(s.size() < 4) s =s + '0';   //   注意 运算一定要是4位的  比如 999 
   }
   loop:;
   return 0;
}
