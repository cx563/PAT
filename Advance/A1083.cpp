#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct stu{
    string name;
    string id;
    gg score;
    bool operator<(const stu& b) const{
        return this->score > b.score;
    }
};
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ni;
   cin>>ni;
   vector<stu>vi(ni);
   for(gg i=0;i<ni;i++) cin>>vi[i].name>>vi[i].id>>vi[i].score;
   sort(vi.begin(),vi.end());  // 记得排序
   gg ai,bi;
   cin>>ai>>bi;
   gg res=0;
   for(auto i: vi){
       if(i.score>=ai and i.score<= bi){
           res++;
           cout<<i.name<<" "<<i.id<<"\n";
       }
   }
   if(not res) cout<<"NONE"<<"\n";
   return 0;
}
