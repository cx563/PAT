#include <bits/stdc++.h>
using namespace std;
using gg = long long;
unordered_map<gg,string>low{{0,"tret"},{1,"jan"},{2,"feb"},{3,"mar"},{4,"apr"},{5,"may"},{6,"jun"},{7,"jly"},{8,"aug"},{9,"sep",},{10,"oct"},{11,"nov"},{12,"dec"}};
unordered_map<gg,string>high{{1,"tam"},{2,"hel"},{3,"maa"},{4,"huh"},{5,"tou"},{6,"kes"},{7,"hei"},{8,"elo"},{9,"syy"},{10,"lok"},{11,"mer"},{12,"jou"}};
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   unordered_map<string,string>res;
   for(gg i=0;i<169;i++){
       string tmp = to_string(i);
       res[tmp] = i > 12 ? high[i / 13] + (i % 13 ==0 ? "" : " "+low[i % 13]) : low[i % 13];
       res[res[tmp]] = tmp;
   }
   gg ni;
   cin >> ni;
   cin.get();
   string s;
   while (ni --){
       getline(cin,s);
       cout << res[s] << "\n";
   }
   return 0;
}