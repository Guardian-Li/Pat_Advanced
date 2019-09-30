#include<iostream>
using namespace std;
long long mp[33554432];
int allone = (1 << 7) - 1;
bool find(int n){
int    index = n >> 6;
  int  bit = n | allone ;
    int bitc = 1 << bit;
    return mp[index] & bitc;
}

void setBit(int n){
   int  index = n >> 6;
   int  bit = n | allone;
    mp[index] = mp[index] | (1<<bit);
}

int main()
{
    int n;
    cin>>n;
    int maxn = 0;
    for(int i=0; i<n; ++i){
        int t;
        cin>>t;
        if(t > 0)
        {
            setBit(t);
            maxn = max(maxn,t);
        }
    }
    for(int i = 1; i <= maxn + 1 ; i++){
        if(!find(i))
        {
            cout<<i;
            break;
        }
    }


    return 0;
}
