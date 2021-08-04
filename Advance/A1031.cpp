#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   string stri;
   cin>>stri;
   gg n1 ,n2,n3;
   n1 = n3 = (stri.size()+2)/3;
   n2 = stri.size() + 2 - n1 - n3;
   for(gg i =0;i<n1 -1;i++){
       cout<<stri[i];
       for(gg j =0;j<n2-2;j++) cout<<" ";
       cout<<stri[stri.size()-1-i]<<endl;
   }
   for(gg i= n1-1,j =0;j<n2;i++,j++) cout<<stri[i];
   return 0;
}
