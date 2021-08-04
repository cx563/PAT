#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg col,row;
   char c;
   cin>>col>>c;
   row = round(col * 1.0 /2);
   for(gg i=0;i<col;i++) cout<<c;
   cout<<"\n";
   for(gg i=0;i<row-2;i++){
       cout<<c;
       for(gg j=0;j<col -2;j++) cout<<" ";
       cout<<c<<endl;
   }
   for(gg i=0;i<col;i++) cout<<c;
   return 0;
}
