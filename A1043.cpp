#include<iostream>
using namespace std;
vector<int> p;
int main
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    p.resize(n+1);
    for(int i=1; i<=n; ++i)
        cin>>p[i]
    if(judge()){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }



}
