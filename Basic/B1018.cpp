#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int c (char c){
    if(c == 'B') return 0;
    else if(c == 'C') return 1;
    else return 2;
}
char mp[3] = {'B','C','J'};
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n;
   cin>>n;
   int A[3]={0};
   int B[3]={0};
   int A_win[3]={0};
   int B_win[3]={0};
   char c1,c2;
   int num1,num2;
   while(n--){
       cin>>c1>>c2;
       num1 = c(c1);
       num2 = c(c2);
       if((num1 +1)%3 == num2){   // 甲赢
            A[0]++;
            A_win[num1]++;
            B[2]++;
       }else if(num1 == num2){
           A[1]++;
           B[1]++;
       }else if((num1 +2) % 3 == num2){
           B[0]++;
           B[num2]++;
           A[2]++;
       }
   }
   cout<<A[0]<<" "<<A[1]<<" "<<A[2]<<"\n";
   cout<<B[0]<<" "<<B[1]<<" "<<B[2]<<"\n";
   int res = 0; 
   int temp =A_win[0];
   for(int i=0;i<3;i++){
       if(A_win[i] > temp) {
           temp = A_win[i];
           res = i;
       }
   }
   cout<<mp[res]<<" ";
   res = 0;
   temp = B_win[0];
   for(int i=0;i<3;i++){
       if(B_win[i] > temp) {
           temp = B_win[i];
           res = i;
       }
   }
   cout<<mp[res];
   return 0;
}
