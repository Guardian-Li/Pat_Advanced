#include<iostream>
using namespace std;
//二进制解
int main()
{
    int n;
    cin>>n;
    int allone;
    for(int i=0; i<n; ++i)
    {
        int k;
        cin>>k;
        int flag = 0;
        int vis[3][1100] = {0};
        for(int j=1; j<=k; ++j)
        {
            int temp;
            cin>>temp;
            if(!vis[0][temp] && !vis[1][temp + j ] && !vis[2][temp-j+k]){
                vis[0][temp] = vis[1][j+temp] = vis[2][temp-j+k] = 1;

            }else{
                flag = 1;
            }


        }
        if(flag){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }

    }
    return 0;

}
