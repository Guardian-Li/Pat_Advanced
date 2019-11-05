#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string strPlus(string a,string b){
    string res = "";
    auto ita = a.rbegin();
    auto itb = b.rbegin();
    int flag = 0;
    int sum = 0;
    while( ita != a.rend() && itb != b.rend()){
        sum = *ita + *itb - '0' - '0' + flag;
        int t = sum %10;
        flag = sum / 10;
        res  += ('0' + t);
        ++ita;
        ++itb;
    }
    while( ita != a.rend()){
        sum = *ita - '0' + flag;
        int t = sum % 10;
        flag = sum / 10;
        res += t +'0';
        ++ita;
    }
    while( itb != b.rend()){
        sum = *itb - '0' + flag;
        int t = sum % 10;
        flag = sum / 10;
        res += t + '0';
        ++itb;
    }
    if(flag){
        res += (flag + '0');
    }
    reverse(res.begin(),res.end());
    return res;

}


int main()
{
    string s;
    int m;
    cin>>s>>m;
    //string tx = "484";

    int flag = 0;
    //cout<<strPlus("120000","0")<<endl;
    for(int i=1; i<=m;++i){

        string b = s;
        reverse(b.begin(),b.end());

        if(s == b){


            break;
        }
        flag++;
        s = strPlus(s,b);

    }
    cout<<s<<endl;
    cout<<flag<<endl;
    return 0;

}
