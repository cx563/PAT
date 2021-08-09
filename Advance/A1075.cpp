#include <bits/stdc++.h>    //  大佬思路 维护一个哈希表 键为学生的id，键值为结构体 也具有id属性 在排序时，遍历哈希表 
using namespace std;        // 把键值依次压入向量中，把键值的id属性用键赋值 便能参与排序 而且 含义明确
using gg = long long;       // 普通数组仅用于常量映射 打表  静态链表  我们使用array
struct stu{
    gg id;
    array<gg,6>score;
    gg rank;
    gg total;
    gg psolved;
    gg flag;

    stu(){
        fill(score.begin(),score.end(),-1);
        rank =0;
        flag = 0;
        psolved =0;
        total =0;
    }
    bool operator<(const stu& b) const{
        if(this->flag != b.flag) return this->flag > b.flag;   // 将不会输出的 放入容器最后面
        else if(this->total != b.total) return this->total > b.total;
        else if(this->psolved != b.psolved) return this->psolved > b.psolved;
        else return this->id<b.id;
    }
};
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ni,ki,mi;
   cin>>ni>>ki>>mi;
   vector<gg>pi(ki+1);  // 题目总分
   for(gg i=1;i<=ki;i++) cin>>pi[i];
   vector<stu>vi(ni+1);
   for(gg i=1;i<=ni;i++) vi[i].id=i;  // 问题的核心 由数组下标直接映射id
   gg idi,scorei,numi;
   for(gg i=0;i<mi;i++){
       cin>>idi>>numi>>scorei;
       if(scorei==-1 and vi[idi].score[numi] == -1) vi[idi].score[numi] =0;
       if(scorei != -1) vi[idi].flag = 1;
       if(scorei == pi[numi] and vi[idi].score[numi] != pi[numi]) vi[idi].psolved++;
       if(scorei > vi[idi].score[numi]) vi[idi].score[numi] = scorei;
   }
   for(gg i=1;i<=ni;i++){
       for(gg j=1;j<6;j++){
           if(vi[i].score[j] != -1) vi[i].total+=vi[i].score[j];
       }
   }
   sort(vi.begin()+1,vi.end());
   vi[1].rank=1;
   for(gg i=2;i<=ni;i++){
       if(vi[i].flag and vi[i].total == vi[i-1].total) vi[i].rank=vi[i-1].rank;
       else vi[i].rank = i;
       if(!vi[i].flag) break;
   }
   for(gg i=1;i<=ni;i++){
       if(vi[i].flag){
           cout<<vi[i].rank<<" ";
           cout<<setfill('0');
           cout<<setw(5)<<vi[i].id<<" "<<vi[i].total;
           for(gg j=1;j<=ki;j++){
               cout<<" ";
               if(vi[i].score[j] == -1) cout<<"-";
               else cout<<vi[i].score[j];
           }
           cout<<"\n";
       }else {
           break;
       }
   }
   return 0;
}
