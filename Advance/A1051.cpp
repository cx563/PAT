#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg m,n,k,t;
   cin>>m>>n>>k;
   while(k--){
       stack<gg>st;  //  栈
       gg j = 1;   //  压栈指针
       for(gg i=1;i<=n;i++){
           cin>>t;
           if(not st.empty() and t == st.top()) st.pop();  //  把刚刚压入的 弹出来
           else{
               while(j <= n and st.size() < m) {
                   if(j == t ){
                       st.push(j++);
                       break;
                   }else st.push(j++);
               }
               if(st.empty() or st.top() != t){   //   这个数据处理不了
                    cout<<"NO\n";
                    while(++i <= n) cin>>t;  //  把数据读完
                    goto loop;
               }else st.pop();    //  处理数据
           }
       }
       cout<<(st.empty() ? "YES\n" : "NO\n");
       loop:;
   }
   return 0;
}
