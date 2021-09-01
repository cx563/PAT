#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n;
   cin>>n;
   vector<gg>vi(n),ti(n),tmp(n);  //  初始序列 比对序列
   for(auto& i : vi) cin>>i;
   for(auto& i : ti) cin>>i;
   tmp = vi;
   for(gg i=2;i<=vi.size();i++){
       sort(tmp.begin(),tmp.begin()+i);
       if(tmp == ti){
           cout<<"Insertion Sort\n";
           sort(tmp.begin(),tmp.begin()+i+1);
           for(gg i=0;i<tmp.size();i++){
               if(i) cout<<" ";
               cout<<tmp[i];
           }
           goto loop;
       }
   }
   tmp = vi;
   make_heap(tmp.begin(),tmp.end());   //  建堆  
   for(gg i=tmp.size();i>0;i--){
       pop_heap(tmp.begin(),tmp.begin()+i);  //   注意迭代区间是左闭右开 总是把堆顶放在有效区间最后 再调整剩余位置元素为大顶堆
       if(tmp == ti){                        //   swap 首位元素 前面元素make_heap 也可以满足要求
           cout<<"Heap Sort\n";
           pop_heap(tmp.begin(),tmp.begin()+i-1);
           for(gg i=0;i<tmp.size();i++){
               if(i) cout<<" ";
               cout<<tmp[i];
           }
           goto loop;
       }
   }
   loop:;
   return 0;
}