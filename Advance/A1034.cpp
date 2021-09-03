#include <bits/stdc++.h>
using namespace std;
using gg = long long;
unordered_map<string,string>ufs;   //   并查集数组
unordered_map<string,gg>weight;    //   结点的权重
map<string,array<gg,2>>res;        //   结果 father 对应 人数 + 权重之和
string findFather(string x){
    return x == ufs[x] ? x : ufs[x] = findFather(ufs[x]);
}
void unionSets(string x, string y){
    auto a = findFather(x), b = findFather(y);
    if(a != b) weight[a] > weight[b] ? ufs[b] = a : ufs[a] = b;  
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n,k,time;
   string name1,name2;
   vector<array<string,2>>v;  
   cin>>n>>k;
   while(n--){
       cin>>name1>>name2>>time;
       if(not ufs.count(name1)) ufs[name1] = name1;
       if(not ufs.count(name2)) ufs[name2] = name2;
       weight[name1] += time;
       weight[name2] += time;
       v.push_back({name1,name2});   //   这里要注意 由于结点的权重不完整 不能在此处进行unionSets 
   }
   for(auto& i : v) unionSets(i[0],i[1]);
   for(auto& i : ufs){  //  统计 father 信息
       res[findFather(i.first)][1] += weight[i.first];
       res[findFather(i.first)][0]++;
   }
   for(auto i = res.begin();i != res.end();){   //   这里 整个帮派的权重和 一定等于 各个结点的权重和 / 2 
       if(i->second[1] / 2 <= k or i->second[0] <= 2) i = res.erase(i);
       else i++;
   }
   cout<<res.size()<<"\n";
   for(auto& i : res){
       cout<<i.first<<" "<<i.second[0]<<"\n";
   }
   return 0;
}


