#include <bits/stdc++.h>   //  为何不像之前一题，维护两个pri队列 customer 和 window ？
using namespace std;      //  原因是这样的 我们需要维护这样的信息，队伍中有没有vip等待球员。如果有，那vip球桌是要优先
using gg = long long;     // 分配给他的，但什么是等待，是他来了之后没有空球桌 而不是他没有来，那我们就要将球桌空闲时间和他到的时间进行比较 若时间早于球桌空闲时刻，这才叫等待 显然这样就相对复杂了 我们将其并入一条时间线 只要此时action是桌子空闲，在等待队列里的vip一定是等待的 逻辑会清晰很多
struct Player{   //  维护每个球员的信息
    gg arrive, server, vip;   //  到达时间 打球时间 是否为vip;
};
struct Action{
    gg tableNum, playerNum, time;  //  球桌编号 占用球桌球员编号 结束时间 或达到时间
    bool operator<(const Action& b)const{
        return tie(b.time) < tie(this->time);  //  根据时间进行优先级  无论是到场 还是 球桌租用结束
    }                                   //  以给球员分配球桌为驱动 将球员的到场 和 球桌的空闲放到一条时间轴上
};                    
void output(gg time){
    cout<<fixed<<setfill('0')<<setw(2)<<time / 3600<<":"<<setw(2)<<time%3600/60<<":"<<setw(2)<<time%60<<" ";
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ni, ki, mi, ai, endTime = 21 * 3600;
   cin>>ni;
   vector<Player>player;
   priority_queue<Action>actions;
   for(gg i=0;i<ni;i++){
       gg h, m, s, p, vip;
       char ch;
       cin>>h>>ch>>m>>ch>>s>>p>>vip;
       player.push_back({h*3600+m*60+s,min(p,120ll) * 60, vip});
       actions.push({-1,i,player[i].arrive});    //  为什么这里初始条件是各个球员的到场时间而没有窗口初始空闲时间？
   }                                            //  原因：球员分配球桌后，显然会入队该球桌下一次空闲时刻，那显然初始空闲时刻是没有含义的  而且，将全部桌子加入初始空闲set 查找也是相当方便 但之后，桌子空闲时间是有明显含义的，需要入队
   cin>>ki>>mi;
   vector<gg>ans(ki);  //  每个球桌被占用的次数
   vector<bool>vip(ki, false);  //  每个球桌是否为vip球桌
   while(mi--){
       cin>>ai;
       vip[ai - 1] = true;
   }
   list<gg>waitPlayer, waitVipPlayer;  //  等待球员 等待的vip球员 前者包含后者
   set<gg>freeTable, freeVipTable;   //  空闲的球桌 空闲的vip球桌
   for(gg i =0;i<ki;i++){
       freeTable.insert(i);
       if(vip[i]) freeVipTable.insert(i);
   }
   while(not actions.empty()){
       auto a = actions.top();
       actions.pop();
       if(a.time >= endTime) break;
       if(a.tableNum == -1){   //  待分配的球员
            if(freeTable.empty()){
                waitPlayer.push_back(a.playerNum);
                if(player[a.playerNum].vip){
                    waitVipPlayer.push_back(a.playerNum);
                }
            }else{
                gg num = -1;  //  分配球桌的编号
                if(player[a.playerNum].vip and not freeVipTable.empty()){  //  对vip球员 优先分配vip球桌
                    num = *freeVipTable.begin();
                    freeVipTable.erase(num);
                    freeTable.erase(num);
                }else{
                    num = *freeTable.begin();
                    freeTable.erase(num);
                    if(vip[num]){
                        freeVipTable.erase(num);
                    }
                }
                actions.push({num,a.playerNum,a.time + player[a.playerNum].server});
                ans[num]++;
                output(a.time);
                output(a.time);
                cout<<"0\n";
            }
       }else{
           if(waitPlayer.empty()){   //  该到期球桌闲置
                freeTable.insert(a.tableNum);
                if(vip[a.tableNum]){
                    freeVipTable.insert(a.tableNum);
                }
           }else{     //  球桌将会被分配给等待的球员
                gg num = -1;  //  被分配球员的编号
                if(vip[a.tableNum] and not waitVipPlayer.empty()){
                    num = waitVipPlayer.front();
                    waitVipPlayer.pop_front();
                    waitPlayer.erase(find(waitPlayer.begin(),waitPlayer.end(),num));
                }else{
                    num = waitPlayer.front();
                    waitPlayer.pop_front();
                    if(player[num].vip){
                        waitVipPlayer.erase(find(waitVipPlayer.begin(),waitVipPlayer.end(),num));
                    }
                }
                actions.push({a.tableNum,num,a.time + player[num].server});
                ans[a.tableNum]++;
                output(player[num].arrive);
                output(a.time);
                cout<<fixed<<setprecision(0)<<round((a.time - player[num].arrive) / 60.0)<<"\n";
           }
       }
   }
   for(gg i=0;i<ki;i++){
       if(i) cout<<" ";
       cout<<ans[i];
   }
   return 0;
}
