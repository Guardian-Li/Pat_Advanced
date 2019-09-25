#include<iostream>
#include<iomanip>
using namespace std;
const int maxn = 1100;
int main()
{
    int n;
    //int e[11];
    double c[maxn] = {0.0};
    double d[maxn] = {0.0};
    double r[maxn*2] = {0.0};
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0; i<n; ++i){
        int exp;
        double cof;
        cin>>exp>>cof;
        c[exp] +=cof;
    }
    cin>>n;
    for(int i=0; i<n; ++i){
        int exp;
        double cof;
        cin>>exp>>cof;
        d[exp] +=cof;
    }
    for(int i=0; i < maxn; ++i){
        for(int j=0; j<maxn; ++j){
            if(c[i] && d[j]){
                r[i+j] += (c[i] * d[j]);
            }
        }
    }
    int cnt = 0;
    for(int i=0; i< 2*maxn; ++i){
        if(r[i])
            cnt ++;
    }
    if(cnt){
        cout<<cnt;
        for(int i = 2*maxn-1; i>=0; i--){
            if(r[i]){
                cout<<" "<<i<<" "<<fixed<<setprecision(2)<<r[i];
            }
        }
    }else{
        cout<<"0 0";
    }
    return 0;

}
