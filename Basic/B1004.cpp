#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   int high = -1;
   int low = 101;
   int n;
   cin>>n;
   array<string,4>res;
   string name,number;
   int score;
   while(n--){
       cin>>name>>number>>score;
       if(score > high) {
           res[0] = name;
           res[1] = number;
           high = score;
       }
       if(score<low){
           res[2] = name;
           res[3] = number;
           low = score;
       }
   }
   cout<<res[0]<<" "<<res[1]<<"\n";
   cout<<res[2]<<" "<<res[3]<<"\n";
   return 0;
}
