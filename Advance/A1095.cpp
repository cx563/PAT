#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct Record{
    string number;
    string date;
    string status;
    bool operator<(const Record& b) const{
        if(this->number!= b.number) return this->number < b.number;
        else return this->date<b.date;
    }
};

gg cost(Record& a,Record& b){
    gg res=0;
    gg h1,m1,s1,h2,m2,s2;
    h1=stoi(a.date.substr(0,2));
    m1=stoi(a.date.substr(3,2));
    s1=stoi(a.date.substr(6,2));
    h2=stoi(b.date.substr(0,2));
    m2=stoi(b.date.substr(3,2));
    s2=stoi(b.date.substr(6,2));
    res = h2*3600+m2*60+s2-h1*3600-m1*60-s1;    //  这里不要再循环计秒了，会导致超时 直接把秒数求出来就可以了
    return res;
}
bool cmp(Record& a,Record& b){
    return a.date<b.date;
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ni,ki;
   map<string,gg>mp;   // 记录每辆车停车的时间
   cin>>ni>>ki;
   vector<Record>vi(ni);
   for(auto& i:vi) cin>>i.number>>i.date>>i.status;
   sort(vi.begin(),vi.end());
   vector<Record>res;
   gg i,j,len;
   len = vi.size();
   gg maxtime=-1;
   for(i=0;i<len;){
       j =i;
       while(j+1<len and vi[j].number == vi[j+1].number){
           if(vi[j].status == "in" and vi[j+1].status == "out"){  // 有效记录
               res.push_back(vi[j]);
               res.push_back(vi[j+1]);
               mp[vi[j].number] += cost(vi[j],vi[j+1]);
               if(mp[vi[j].number] > maxtime) maxtime = mp[vi[j].number];
           }
           j++;
       }
       i = ++j;
   }
   sort(res.begin(),res.end(),cmp);
   string query;
   gg res2=0; // 汽车数量
   i=0;
   gg len2 = res.size();
   while(ki--){
       cin>>query;
       for(;i<len2 and res[i].date <=query;i++){
           if(res[i].status == "in") res2++;
           else res2--;
       }
       cout<<res2<<"\n";
   }
   for(auto i:mp){
       if(i.second == maxtime) cout<<i.first<<" ";
   }
   cout<<setfill('0')<<setw(2)<<maxtime/3600<<":"<<setw(2)<<(maxtime%3600)/60<<":"<<setw(2)<<maxtime%60;
   return 0;
}
