/*#include <bits/stdc++.h>   // 没处理溢出 22分
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg tag,radix;
   string n1,n2;
   cin>>n1>>n2>>tag>>radix;
   unordered_map<char,gg>mp;
   for(char i ='0';i<='9';i++) mp[i]=i-'0';
   for(char i ='a';i<='z';i++) mp[i]=i-'a'+10;
   if(tag == 2) swap(n1,n2);  // n2是未知数
   gg cnt =0;
   for(auto i : n1){
       cnt = cnt * radix +mp[i];
   }
   vector<gg>biao;
   for(gg i=2;i<=200;i++){
       gg cnt2=0;
       for(auto j : n2){
           cnt2 = cnt2 *i + mp[j];
       }
       biao.push_back(cnt2);
   }
   auto j = lower_bound(biao.begin(),biao.end(),cnt);
   if(j == biao.end() or *j != cnt) cout<<"Impossible"<<"\n";
   else cout<<(j-biao.begin())+2<<"\n";
   return 0;
}*/

#include <bits/stdc++.h>
using namespace std;
using gg = long long;
string s1,s2;
gg tag,radix;
unordered_map<char,gg>um;
gg rToDec(const string& r,gg radix){
    gg d=0;
    for(auto i : r){
        d = d* radix + um[i];
    }
    return d;
}
gg binarySearchF(gg left,gg right,gg n){    // lower_bound模型
    while(left < right){
        gg mid = (left+right)/2;
        auto k = rToDec(s2,mid);
        if(k >= n or k < 0) right = mid;
        else  left = mid +1;
    }
    auto k = rToDec(s2,left);
    return (k == n ? left : -1);
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin>>s1>>s2>>tag>>radix;   //  我们要求两个数均位于十进制下 值相等 已知n1的进制 求是否存在n2的进制 使两者相等
   if(tag ==2) swap(s1,s2);
   for(gg i=0;i<36;i++){
       i < 10 ? (um[i+'0'] =i) : (um['a'+(i-10)] =i); 
   }
   gg n = rToDec(s1,radix);
   auto m= max_element(s2.begin(),s2.end(),[] ( char c1,char c2){
       return um[c1] < um[c2];
   });
   gg left = um[*m]+1;
   gg ans = binarySearchF(left,max(left,n)+1,n);
   ans == -1 ? cout<<"Impossible" : cout<<ans;
   return 0;
}
