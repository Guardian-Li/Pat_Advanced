#include<iostream>
#include<vector>
using namespace std;
const int N = 500005;
int p[N];
int c[N];

inline int lowbit(int x){
    return x&(-x);
}

void update(int x,int k){
    while( x <= N )
    {
        p[x] += k;
        x += lowbit(x);
    }
}

int get_sum(int x){
    int sum = 0;
    while( x  ){
        sum += p[x];
        x -= lowbit(x);
    }
    return sum;

}

int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1; i <= n; ++i){
        cin>>c[i];
    }
    for(int i=1; i<=n; ++i){
        update(i,c[i]);
    }
    for(int i=0; i<m; ++i){
        int k,a,b;
        cin>>k>>a>>b;
        if( k == 1){
            update(a,b);
        }
        if(k == 2){

            cout<<get_sum(b)-get_sum(a-1)<<endl;
        }
    }
    return 0;


}
