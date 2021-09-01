#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct node{
    array<gg,2>child;
    gg val;
};
vector<node>tree(1e2 + 10);
vector<gg>res;
void inorder(gg root,vector<gg>& key,gg& index){
    if(root == -1) return;
    inorder(tree[root].child[0],key,index);
    tree[root].val = key[index++];
    inorder(tree[root].child[1],key,index);
}
void BFS(gg root){
    queue<gg>q;
    q.push(root);
    while(not q.empty()){
        gg top = q.front();
        q.pop();
        res.push_back(tree[top].val);
        if(tree[top].child[0] != -1) q.push(tree[top].child[0]);
        if(tree[top].child[1] != -1) q.push(tree[top].child[1]);
    }
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n,index = 0;
   cin>>n;
   vector<gg>key(n);
   for(gg i=0;i<n;i++) cin>>tree[i].child[0]>>tree[i].child[1];
   for(gg i=0;i<n;i++) cin>>key[i];
   sort(key.begin(),key.end());
   inorder(0,key,index);
   BFS(0);
   for(gg i=0;i<n;i++){
       if(i) cout<<" ";
       cout<<res[i];
   }
   return 0;
}
