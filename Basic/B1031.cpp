#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   vector<gg> vi{7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
   vector<char> vdi{'1' ,'0', 'X', '9', '8', '7', '6', '5' ,'4', '3', '2'};
   gg ni;
   cin>>ni;
   string stri;
   bool flag =true;
   while(ni--){
       cin>>stri;
       gg temp = 0;
       for(gg i=0;i<17;i++) {
           if(!isdigit(stri[i])){
               flag = false;
               cout<<stri<<"\n";
               temp = 0;
               break;
           }
           temp += (stri[i]-'0') * vi[i];  
        }
        if(temp) {
            temp %=11;
            if(stri[17] != vdi[temp]) {
                cout<<stri<<"\n";
                flag = false;
            }
        }
    }
    if (flag) cout<<"All passed";
   return 0;
}
