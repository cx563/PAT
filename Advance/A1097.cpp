#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg maxn = 100010;
struct node{
    gg address,key,next;
    node(){
        address = -1;
    }
};
array<node,maxn>ar;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   unordered_map<gg,bool>um;  //  哈希表
   gg ad,n,a,b,c;
   cin>>ad>>n;
   for(gg i=0;i<n;i++){
       cin>>a>>b>>c;
       ar[a].address = a;
       ar[a].key = b;
       ar[a].next = c;
   }
   vector<node>res1,res2;   //   链表和线性表都是顺序容器 用线性表模拟链表有很多方便之处
   while(ad != -1){
       if(not um[abs(ar[ad].key)]) {
           um[abs(ar[ad].key)] = true;
           res1.push_back(ar[ad]);
       }else res2.push_back(ar[ad]);
       ad = ar[ad].next;
   }
   res1.push_back(node());
   res2.push_back(node());
   for(gg i=0;i<res1.size()-1;i++){
       cout<<setfill('0')<<setw(5)<<res1[i].address<<" "<<res1[i].key<<" ";
       if(res1[i+1].address != -1) cout<<setw(5);
       cout<<res1[i+1].address<<"\n";
   }
   for(gg i=0;i<res2.size()-1;i++){
       cout<<setfill('0')<<setw(5)<<res2[i].address<<" "<<res2[i].key<<" ";
       if(res2[i+1].address != -1) cout<<setw(5);
       cout<<res2[i+1].address<<"\n";
   }
   return 0;
}
