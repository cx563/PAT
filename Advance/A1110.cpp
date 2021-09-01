#include <bits/stdc++.h>
using namespace std;
using gg = long long;
vector<array<gg,2>>tree(100);
vector<gg>res;
bool BFS(gg root){
    queue<pair<gg,gg>>q;
    q.push({root,1});
    gg i = 1;
    while(not q.empty()){   //  很好的思路 利用完全二叉树的性质 对结点进行1 到 n 的编码 进行层次遍历 遍历序列正好是 1 到 n 
        auto top = q.front();
        q.pop();
        res.push_back(top.first);
        if(top.second != i) {
            return false;
        }
        if(tree[top.first][0] != -1) q.push({tree[top.first][0],2 * i});
        if(tree[top.first][1] != -1) q.push({tree[top.first][1],2 * i + 1});
        i++;
    }
    return true;
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n;
   cin>>n;
   string l,r;
   vector<bool>flag(100,false);
   for(gg i=0;i<n;i++){
       cin>>l>>r;
       if(l == "-") tree[i][0] = -1;
       else{
           tree[i][0] = stoll(l);
           flag[tree[i][0]] = true;
       }
       if(r == "-") tree[i][1] = -1;
       else{
           tree[i][1] = stoll(r);
           flag[tree[i][1]] = true;
       }
   }
   gg root = find(flag.begin(),flag.begin()+n,false) - flag.begin();
   if(BFS(root)){
       cout<<"YES"<<" "<<res.back();
   }else{
       cout<<"NO"<<" "<<res.front();
   }
   return 0;
}
