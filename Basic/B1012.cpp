#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   int res[5];  // 结果
   int cont[5]; // 计数
   memset(res,0,sizeof(res));
   memset(cont,0,sizeof(cont));
   int n;
   cin>>n;
   int num  =0;
   while(n--){
       cin>>num;
       if(num % 5 ==0 ){  //  注意这里 num % 5 和 num % 2 不能并列 否则 会导致进入 else 语句中  
           if(num % 2 == 0){
             res[0] += num;
             cont[0]++;
           }
       }else if(num % 5 ==1){
           cont[1]++;
           if(cont[1] % 2 == 1){
               res[1] += num;
           }else {
               res[1]-= num;
           }
       }else if(num % 5 == 2){
            cont[2]++;
       }else if(num % 5 ==3){
           res[3]+=num;
           cont[3]++;
       }else{
           if(num > res[4]){
               res[4] = num;
           }
           cont[4]++;
       }
   }
   for(int i=0;i<5;i++){
       if(i) printf(" ");
       if(!cont[i]) printf("N");
       else if(i == 3)  printf("%.1f", (res[3]  * 1.0 / cont[3]));
       else if(i == 2)  printf("%d",cont[2]);
       else printf("%d",res[i]);
   }
   return 0;
}


