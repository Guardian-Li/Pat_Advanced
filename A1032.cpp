#include<iostream>
using namespace std;
bool judge(int n)
{
    int cnt = 0;
    int t = n;
    while(t){
        cnt++;
        t/=10;
    }
    cnt = cnt  / 2;
    int p = 1;
    for(int i=0; i<cnt; ++i){
        p *= 10;
    }
    int a = n % p;
    int b = n / p;
    double res ;
    res = (double)n / (double)(a*b);
    if( a && b && res == n/(a*b) )
        return true;
    else
        return false;
}
int main()
{
    int n;
    int k;
    cin>>k;
    for(int i=0; i<k; ++i){
        cin>>n;
        if(judge(n)){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;

}
