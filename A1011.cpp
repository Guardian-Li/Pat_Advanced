#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    char table[3] = {'W','T','L'};
    double tax = 1;
    int flag[3] = {0};
    for(int i=0; i<3;++i){
        double t = -1;
        for(int j=0; j<3; ++j){
            double tmp;
            cin>>tmp;
            if( tmp > t){
                flag[i] = j;
                t = tmp;

            }
        }
        tax *= t;
    }
    for(int i = 0; i<3; ++i){
        cout<<table[flag[i]]<<" ";
    }
    cout<<fixed<<setprecision(2)<<(tax*0.65-1)*2<<endl;
}
