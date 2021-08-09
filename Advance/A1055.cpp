#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct Person{
    string name;
    gg age;
    gg worth;

    bool operator < (const Person& b) const{
        if(this->worth != b.worth) return this->worth > b.worth;
        else if(this->age != b.age) return this->age < b.age;
        else return this->name < b.name;
    }
};
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ni,ki;
   cin>>ni>>ki;
   vector<Person>vi(ni);
   for(gg i=0;i<ni;i++){
       cin>>vi[i].name>>vi[i].age>>vi[i].worth;
    }
    sort(vi.begin(),vi.end());
    gg numi,ai,bi;
    for(gg i=1;i<=ki;i++){
        cin>>numi>>ai>>bi;
        gg cont =0;
        cout<<"Case #"<<i<<":"<<"\n";
        for(gg j=0;j<ni and cont <numi;j++){
            if(vi[j].age>= ai and vi[j].age <= bi){
                cont++;
                cout<<vi[j].name<<" "<<vi[j].age<<" "<<vi[j].worth<<"\n";
            }
        }
        if(cont==0) cout<<"None"<<"\n";
    }
   return 0;
}
