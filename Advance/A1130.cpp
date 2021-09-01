#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct node{
    string str;
    gg left,right;
};
vector<node>tree(100);
void inorder(gg root,gg r){
    if(root == -1) return ;
    if(root != r and (tree[root].left != -1 or tree[root].right != -1)) cout<<"(";  //   注意这里的条件判断
    inorder(tree[root].left,r);
    cout<<tree[root].str;
    inorder(tree[root].right,r);
    if(root != r and (tree[root].left != -1 or tree[root].right != -1)) cout<<")";
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n,l,r;
   cin>>n;
   vector<bool>flag(100,false);
   for(gg i=1;i<=n;i++){
       cin>>tree[i].str>>l>>r;
       tree[i].left = l,tree[i].right = r;
       if(l != -1) flag[l] = true;
       if(r != -1) flag[r] = true;
   }
   gg root = find(flag.begin()+1,flag.begin()+n+1,false) - flag.begin() ;
   inorder(root,root);
   return 0;
}
