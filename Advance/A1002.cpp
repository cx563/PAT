#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const int maxn = 1111;
double p[maxn];
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   int k;
   cin>>k;
   int exp;
   double px;
   while(k--){
       cin>>exp>>px;
       p[exp] += px;
   }
   cin>>k;
   while(k--){
       cin>>exp>>px;
       p[exp] += px;
   }
   int res= 0;
   for(int i=0;i<1111;i++){
       if(p[i] != 0) res++;
   }
   printf("%d",res);
   for(int i = 1110;i>=0;i--){
       if(p[i] !=0){
           printf(" %d %.1f",i,p[i]);
       }
   }
   return 0;
}
