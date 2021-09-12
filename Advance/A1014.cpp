#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct Customer{
    gg endTime, number, w;  //  处理结束时间 顾客编号 顾客窗口编号
    bool operator<(const Customer& b) const{
        return tie(b.endTime, b.number) < tie(this->endTime, this->number);
    }
};
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   priority_queue<Customer>q;   //  模拟顾客入队   关键是顾客出队时体现了优先队列的性质
   gg ni, mi, ki, qi, endTime = 17 * 60, ai;
   cin>>ni>>mi>>ki>>qi;
   vector<gg>ans(ki,INT_MAX);  //  初始均未被处理
   vector<gg>peoplenum(ni), time(ni,8 * 60);  //  维护每个队列中人的数量 最后一个顾客处理完的时间
   for(gg i =0;i<ki;i++){
       cin>>ai;
       if(q.size() >= ni * mi){   //   优先级体现在出队的时间上
           auto c = q.top();
           q.pop();
           peoplenum[c.w]--;
       }
       gg j = min_element(peoplenum.begin(),peoplenum.end()) - peoplenum.begin();
       peoplenum[j]++;    //  这里必须要加
       if(time[j] >= endTime) continue;
       time[j] += ai;
       q.push({time[j],i,j});
       ans[i] = time[j];
   } 
   for(gg i =0;i<qi;i++){
       cin>>ai;
       if(ans[ai-1] == INT_MAX){
           cout<<"Sorry\n";
       }else{
           cout<<setw(2)<<setfill('0')<<ans[ai-1]/60<<":"<<setw(2)<<ans[ai-1]%60<<"\n";
       }
   }
   return 0;
}
