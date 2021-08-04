#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct Person{
    string name;
    gg y,m,d;
    Person(gg yy,gg mm,gg dd):y(yy),m(mm),d(dd) {}
    bool operator < (const Person& p) const{
        if(y != p.y) return y>p.y;
        else if(m != p.m) return m>p.m;
        else return  d>p.d;
    }
};
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ni,num=0;
   cin>>ni;
   Person old(2014,9,6),young(1814,9,6),b1 = old,b2=young;
   Person temp(0,0,0);
   char c;
   while(ni--){
       cin>>temp.name>>temp.y>>c>>temp.m>>c>>temp.d;
       if(b2 < temp  or temp < b1) continue;
       num++;
       if(old < temp) old = temp;
       if(temp < young) young = temp;
   }
   if(num == 0) cout<<"0";
   else {
       cout<<num;
       cout<<" "<<old.name<<" "<<young.name;
   }
   return 0;
}
