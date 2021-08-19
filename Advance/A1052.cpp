#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg maxn = 100010;
struct node{
    gg key,address,next;
    node(){
        address = -1;
    }
};
vector<node>v(maxn);
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n,ad,a,b,c;
   cin>>n>>ad;
   for(gg i=0;i<n;i++){
       cin>>a>>b>>c;
       v[a].address = a;
       v[a].key = b;
       v[a].next = c;
   }
   vector<node>res;
   while(ad != -1){
       res.push_back(v[ad]);
       ad = v[ad].next;
   }
   if(res.size() == 0) {
       cout<<"0 -1";
       goto loop;
   }
   sort(res.begin(),res.end(),[] (const node& a,const node& b){
       return a.key < b.key;
   });
   cout<<res.size()<<" "<<setfill('0')<<setw(5)<<res[0].address<<"\n";
   res.push_back(node());
   for(gg i=0;i<res.size()-1;i++){
       cout<<setw(5)<<res[i].address<<" "<<res[i].key<<" ";
       if(res[i+1].address != -1) cout<<setw(5);
       cout<<res[i+1].address<<"\n";
   }
   loop:;
   return 0;
}
