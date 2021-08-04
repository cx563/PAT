#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int start[55];
int ed[55];
int temp[55];
char mp[5] = {'S','H','C','D','J'};
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n;
   cin>>n;
   for(int i=1;i<=54;i++){
       start[i] = i;
       ed[i] = i;
   }
   for(int i=1;i<=54;i++) cin>>temp[i];
   while(n--){
       for(int i= 1;i<= 54;i++){
           ed[temp[i]] = start[i];
       }
       for(int i=1;i<=54;i++){
           start[i] = ed[i];
       }
   }
   for(int i=1;i<=54;i++){
       if(i != 1) cout<<" ";
       cout<<mp[(start[i]-1)/13]<<(start[i]-1) % 13 + 1;
   }
   return 0;
}
