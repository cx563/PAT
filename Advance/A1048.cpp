#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ni,mi;
   cin>>ni>>mi;
   vector<gg>vi(ni);
   for(auto& i : vi) cin>>i;
   sort(vi.begin(),vi.end());
   gg i=0,j=ni-1;
   while(i<j){
       if(vi[i]+vi[j] == mi) {
           cout<<vi[i]<<" "<<vi[j];
           goto loop;
       }else if(vi[i]+vi[j]<mi){
           i++;
       }else{
           j--;
       }
   }
   cout<<"No Solution"<<"\n";
   loop:;
   return 0;
}
