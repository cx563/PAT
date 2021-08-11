#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ni;
   cin>>ni;
   vector<gg>yi(ni);   // 元素序列
   for(auto& i : yi) cin>>i;
   vector<gg>mi(ni);   // 中间序列
   for(auto& i : mi) cin>>i;
   vector<gg>tmp = yi; 
   for(gg i=2;i<=ni;i++){
       sort(tmp.begin(),tmp.begin() + i);
       if(tmp == mi) {
           cout<<"Insertion Sort\n";
           sort(tmp.begin(),tmp.begin() + i + 1);
           for(gg i=0;i<ni;i++) {
               if(i) cout<<" ";
               cout<<tmp[i];
           }
           goto loop;
       }
   }
   tmp = yi;
   for(gg k =2;k <= ni;k *= 2){
       gg i=0;
       while( i + k <= ni ) {
           sort(tmp.begin()+i,tmp.begin()+i+k);
           i += k;
       }
       if(i < ni) sort(tmp.begin()+i,tmp.end());
       if(tmp == mi) {
           cout<<"Merge Sort\n";
           k *= 2;
           i = 0;
           while( i + k <= ni ) {
                sort(tmp.begin()+i,tmp.begin()+i+k);
                i += k;
            }
            if(i < ni) sort(tmp.begin()+i,tmp.end());
           for(gg i=0;i<ni;i++) {
               if(i) cout<<" ";
               cout<<tmp[i];
           }
           goto loop;
       }
   }
   loop :;
   return 0;
}