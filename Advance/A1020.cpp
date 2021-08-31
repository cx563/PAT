#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct node{
    gg val;
    node* left,* right;
    node(){
        left = right = nullptr;
    }
};
node* build(vector<gg>& post,vector<gg>& in,gg index,gg left,gg right){
    if(left > right) return nullptr;
    gg i = find(in.begin(),in.end(),post[index]) - in.begin();  //   根节点在中序的位置
    node* l = build(post,in,index-1-right+i,left,i-1);
    node* r = build(post,in,index-1,i+1,right);
    node* root = new node;   //  后序建树的模式 其实 和 遍历的思想差不多
    root ->val = post[index];
    root->left = l;
    root ->right = r;
    return root;
}
vector<gg>res;
void BFS(node* root){
    queue<node*> q;
    q.push(root);
    while(not q.empty()){
        node* top = q.front();
        q.pop();
        res.push_back(top->val);
        if(top->left) q.push(top->left);
        if(top->right) q.push(top->right);
    }
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ni;
   cin>>ni;
   vector<gg>post(ni),in(ni);
   for(auto& i : post) cin>>i;
   for(auto& i : in) cin>>i;
   node* root = build(post,in,post.size()-1,0,in.size()-1);
   BFS(root);
   for(gg i=0;i<res.size();i++){
       if(i) cout<<" ";
       cout<<res[i];
   }
   return 0;
}
