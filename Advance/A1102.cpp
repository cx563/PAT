#include <bits/stdc++.h>
using namespace std;
using gg = long long;
vector<gg>res;
void inorder(gg root,vector<array<gg,2>>& tree){
    if(root == -1) return ;
    inorder(tree[root][0],tree);
    res.push_back(root);
    inorder(tree[root][1],tree);
}
void BFS(gg root,vector<array<gg,2>>& tree){
    queue<gg>q;
    q.push(root);
    while(not q.empty()){
        gg top = q.front();
        q.pop();
        res.push_back(top);
        if(tree[top][0] != -1) q.push(tree[top][0]);
        if(tree[top][1] != -1) q.push(tree[top][1]);
    }
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n;
   cin>>n;
   vector<array<gg,2>>tree(n);
   string s;
   vector<bool>flag(n,false);
   for(gg i=0;i<n;i++){
       for(gg j=1;j>=0;j--){
           cin>>s;
           if(s != "-") {
               tree[i][j] = stoll(s);
               flag[tree[i][j]] = true;
           }
           else tree[i][j] = -1;
       }
   }
   gg root = find(flag.begin(),flag.end(),false) - flag.begin();  //  这个正好就应该是根结点的下标
   BFS(root,tree);
    for(gg i=0;i<res.size();i++){
       if(i) cout<<" ";
       cout<<res[i];
   }
   cout<<"\n";
   res.clear();
   inorder(root,tree);
   for(gg i=0;i<res.size();i++){
       if(i) cout<<" ";
       cout<<res[i];
   }
   return 0;
}
