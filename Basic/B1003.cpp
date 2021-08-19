#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n;
   string s;
   cin>>n;
   while(n--){
       cin>>s;
       gg left=0,right=0,numA=0,other=0;
       for(auto i : s){
           if(i != 'P' and i != 'A' and i != 'T'){
                other++;
           }else if(i == 'P') left++;
           else if(i == 'T') right++;
       }
       if(other or left != 1 or right != 1){   //  确保一定是有 P T 的
           cout<<"NO\n";
           goto loop;
       }
       left = s.find('P');  //  左边A的个数
       right = s.size() - s.find('T') - 1;
       numA = s.find('T') - left - 1;
       if(not numA) {
            cout<<"NO\n";
            goto loop;
       }
       if(left == right - (numA - 1) * left) cout<<"YES\n";
       else cout<<"NO\n";
       loop:;
   }
   return 0;
}
