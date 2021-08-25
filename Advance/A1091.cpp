#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct node{
    gg x,y,z;
}Node;
gg n,m,s,T;
gg pixel[1290][130][61];   //   三维矩阵就是这样表示 读入时先枚举高 再枚举行 再枚举列
bool inq[1290][130][61];
//   设置增量数组 每次在top的基础上加减增量
gg X[6]{0,0,0,0,1,-1};
gg Y[6]{0,0,1,-1,0,0};
gg Z[6]{1,-1,0,0,0,0};
bool judge(gg x,gg y,gg z){
    if(x <0 or x >=n or y < 0 or y >= m or z <0 or z >=s) return false;
    if(pixel[x][y][z] == 0 or inq[x][y][z]) return false;
    return true;
}
gg BFS(gg x,gg y,gg z){
    Node.x = x,Node.y = y,Node.z = z;
    gg tot =0;
    queue<node>q;
    q.push(Node);
    inq[x][y][z] = true;
    while(not q.empty()){
        node top = q.front();
        q.pop();
        tot++;
        for(gg i=0;i<6;i++){
            gg newX = top.x + X[i];
            gg newY = top.y + Y[i];
            gg newZ = top.z + Z[i];
            if(judge(newX,newY,newZ)){
                Node.x = newX,Node.y = newY,Node.z = newZ;
                q.push(Node);
                inq[newX][newY][newZ] = true;
            } 
        }
    }
    if(tot >= T) return tot;
    else return 0;
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>m>>s>>T;
   for(gg z = 0;z < s;z++){
       for(gg x = 0;x < n;x++){
           for(gg y = 0;y < m;y++){
               cin>>pixel[x][y][z];
           }
       }
   }
   gg res =0;
   for(gg z = 0;z < s;z++){
       for(gg x = 0;x < n;x++){
           for(gg y = 0;y < m;y++){
             if(pixel[x][y][z] == 1 and not inq[x][y][z]){
                 res += BFS(x,y,z);
             }  
           }
       }
   }
   cout<<res;
   return 0;
}

