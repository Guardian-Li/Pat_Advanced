#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//big integer plus
string p(string a, string b){
    string res = "";
    auto itb = b.rbegin();
    auto ita = a.rbegin();
    int f = 0;
    while(ita != a.rend() && itb != b.rend()){
        res += ((*ita - '0') + (*itb - '0') + f) % 10 + '0';
        f = ((*ita - '0') + (*itb - '0') + f) / 10;
        ++ita;
        ++itb;
    }
    while(ita != a.rend()){
        res += (f + *ita - '0') % 10;
        f = (f + *ita - '0') / 10;
        ++ita;
    }
    while( itb != b.rend()){
        res += (f + *itb - '0') % 10;
        f = (f + *itb - '0') / 10;
        ++itb;
    }
    if(f){
        res += to_string(f);
    }
    reverse(res.begin(),res.end());
    return res;
}


bool isp(string s){
    for(int i=0; i<s.size()/2; ++i){
        if(s[i] != s[s.size() - i - 1]){
            return false;
        }
    }
    return true;

}
int main()
{
    string a;
    cin>>a;
    int flag = 0;
    for(int i=0; i<10; ++i){
        if( isp(a)){
            cout<<a<<" is a palindromic number."<<endl;
            flag = 1;
            break;
        }
        string s = a;
        reverse(s.begin(),s.end());
        string res = p(a,s);
        cout<<a << " + "<<s<<" = "<< res <<endl;
        a = res;
    }
    if(flag == 0){
        cout<<"Not found in 10 iterations."<<endl;
    }
    return 0;


}
