#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   array<map<string,vector<string>>,6>ar;  // 存储结构
   gg ni;
   string name,s,tmp;
   cin >> ni;
   cin.get();
   while (ni--){
       getline(cin,name);
       for (gg i =1;i <=5 ;i++){
           getline(cin,s);
           if (i== 3){
               stringstream ss(s);
               while (ss >> tmp){
                   ar[i][tmp].push_back(name);
               }
               continue;
           }
           ar[i][s].push_back(name);
       }
   }
   for(gg i=1;i<=5;i++){
       for(auto& ii : ar[i]){
           sort(ii.second.begin(),ii.second.end());
       }
   }
   gg query;
   cin >> query;
   cin.get();
   while (query--){
       getline(cin,s);
       cout << s <<"\n";
       tmp = s.substr(3);
       if (ar[s[0]-'0'][tmp].size() == 0){
           cout << "Not Found\n";
           continue;
       }
       for(auto i : ar[s[0]-'0'][tmp]){
           cout<< i << "\n";
       }
   }
   return 0;
}

