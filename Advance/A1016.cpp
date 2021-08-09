#include <bits/stdc++.h>
using namespace std;
using gg = long long;
unordered_map<gg,gg>mp;  // 每小时的汇率
struct Record{
    string name;
    string date;
    string status;  // 上线 还是下线
    bool operator<(const Record& b) const{  // 事实上 这里时间在整体上来看 是无序的 在一个id上来看 是有序的
        if(this->name!= b.name) return this->name<b.name;
        else return this->date<b.date;
    }
};
pair<gg,gg> cost(Record& a,Record& b){
    gg d1,h1,m1,d2,h2,m2;
    d1=stoi(a.date.substr(3,2));
    h1=stoi(a.date.substr(6,2));
    m1=stoi(a.date.substr(9,2));
    d2=stoi(b.date.substr(3,2));
    h2=stoi(b.date.substr(6,2));
    m2=stoi(b.date.substr(9,2));
    gg res=0;
    gg res2=0;
    while(d1 < d2 or h1 < h2 or m1 < m2){
        res2++;
        m1++;
        res+=mp[h1];
        if(m1 ==60){
            m1=0;
            h1++;
        }
        if(h1 ==24){
            h1=0;
            d1++;
        }
    }
    return {res,res2};
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   for(gg i=0;i<24;i++) cin>>mp[i];
   gg ni;
   cin>>ni;
   vector<Record>vi(ni);
   for(auto& i : vi) cin>>i.name>>i.date>>i.status;
   sort(vi.begin(),vi.end());
   gg i,len,j; // i是慢指针 维护区间起点 j是快指针 用于遍历记录
   len = vi.size();
   vector<pair<Record,gg>>res;
   for(i=0;i<len;){
       j = i;
       while(j+1 < len and vi[j].name == vi[j+1].name){
           if(vi[j].status == "on-line" and vi[j+1].status == "off-line"){
               res.push_back({vi[j],j});  // 产生结果
           }
           j++;
       }
       // 个人记录匹配结束   开始输出
       if(res.size()){
           cout<<vi[i].name<<" "<<setfill('0')<<setw(2)<<stoi(vi[i].date.substr(0,2))<<"\n";
           gg total =0;
           for(auto k : res){
               cout<<k.first.date.substr(3)<<" "<<vi[k.second+1].date.substr(3);
               auto fire = cost(k.first,vi[k.second+1]);
               total+=fire.first;
               cout<<" "<<fire.second;
               cout<<" "<<fixed<<setprecision(2)<<"$"<<fire.first/100.0<<"\n";
           }
           cout<<"Total amount: $"<<fixed<<setprecision(2)<<total/100.0<<"\n";
       }
       res.clear();
       i = ++j;
   }
   return 0;
}
