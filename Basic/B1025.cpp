#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg maxn = 100001;
struct node{
    gg address,next,data;
    node (){
        next = -1;
        address = -1;
    }
};
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ad,n,k,a,b,c;
   cin>>ad>>n>>k;
   vector<node>v(maxn);    //  用数组模拟 完全可以把链表想成一个数组 数组顺序就是链表顺序 链表也是顺序结构
   for(gg i=0;i<n;i++){
       cin>>a>>b>>c;
       v[a].address = a;
       v[a].data = b;
       v[a].next = c;
   }
   vector<node>res;   //  反转之后 顺序即使next
   while(ad != -1){   //  所有有效节点
       res.push_back(v[ad]);
       ad = v[ad].next;
   }
   gg i=0;
   while(i + k <= res.size()){
       reverse(res.begin()+i,res.begin()+i+k);
       i = i + k;
   }
   res.push_back(node());
   cout<<setfill('0');
   for(gg i=0;i<res.size()-1;i++){
       cout<<setw(5)<<res[i].address<<" "<<res[i].data<<" ";
       if(res[i+1].address != -1) cout<<setw(5);
       cout<<res[i+1].address<<"\n";
   }
   return 0;
}
