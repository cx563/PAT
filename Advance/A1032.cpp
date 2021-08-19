#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg maxn = 100010;
struct node{
    char data;
    gg address,next;
    gg flag;
    node(){
        flag = 0;
    }
};
vector<node>v(maxn);
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ad1,ad2,n,a,c;
   char b;
   cin>>ad1>>ad2>>n;
   for(gg i=0;i<n;i++){
       cin>>a>>b>>c;   //   cin 自动跳过空字符 读char时也一样
       v[a].address = a;
       v[a].data = b;
       v[a].next = c;
   }
   while(ad1 != -1){
       v[ad1].flag = 1;
       ad1 = v[ad1].next;
   }
   while(ad2 != -1){
       if(v[ad2].flag == 1){
           cout<<setfill('0')<<setw(5)<<v[ad2].address;
           goto loop;
       }
       ad2 = v[ad2].next;
   }
   if(ad2 == -1) cout<<-1;
   loop:;
   return 0;
}
