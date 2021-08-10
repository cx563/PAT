    #include <bits/stdc++.h>
    using namespace std;
    using gg = long long;
    int main()
    {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    for(auto i : s1){
        if(s2.find(i) == -1){
            cout<<i;
        }
    }
    return 0;
    }
