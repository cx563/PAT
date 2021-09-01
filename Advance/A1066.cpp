#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct node{
    node* left,* right;
    gg val,hight;
    node(){
        left = right = nullptr;
        hight = 1;
    }
};
gg getHight(node* root){
    if(root == nullptr) return 0;
    else return root->hight;
}
void updateHeight(node* root){
    root ->hight = max(getHight(root->left),getHight(root->right)) + 1;
}
gg getBalanceFactor(node* root){
    return getHight(root->left) - getHight(root->right);
}
void L(node*& root){
    node* tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}
void R(node*& root){
    node* tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}
void insert(node* & root,gg val){
    if(root == nullptr) {
        root = new node;
        root->val = val;
        return;
    }
    if(val < root->val) {
        insert(root->left,val);
        updateHeight(root);
        if(getBalanceFactor(root) == 2){
            if(getBalanceFactor(root ->left) == 1){
                R(root);
            }else{
                L(root->left);
                R(root);
            }
        }
    }else{
        insert(root->right,val);
        updateHeight(root);
        if(getBalanceFactor(root) == -2){
            if(getBalanceFactor(root->right) == -1) {
                L(root);
            }else{
                R(root->right);
                L(root);
            }
        }
    }
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   node* root = nullptr;
   gg n,val;
   cin>>n;
   while(n--){
       cin>>val;
       insert(root,val);
   }
   cout<<root->val;
   return 0;
}
