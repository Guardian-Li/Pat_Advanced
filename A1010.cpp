#include<iostream>
#include<string>
using namespace std;
typedef long long ll;

ll change(string s,int radix){
    ll k = 1;
    ll sum = 0;
    for(auto it = s.rbegin(); it != s.rend(); ++it){
        ll tmp ;
        if(*it >= 'a' && *it <= 'z'){
            tmp = *it - 'a' + 10;

        }else{
            tmp = *it - '0';
        }
        sum = sum + tmp*k;

        k *= radix;

    }
    return sum;

}

int main()
{
    string a,b;
    int tag,radix;
    ll res;
    cin>>a>>b>>tag>>radix;
    if(tag == 2)
        swap(a,b);
    res = change(a,radix);
    int maxn = -1;
    for(int i=0; i<b.length(); ++i){
        int tmp;
        if(b[i] >= 'a' && b[i] <= 'z'){
            tmp = b[i] - 'a' + 10;
        }else{
            tmp = b[i] - '0';
        }
        if(tmp > maxn)
            maxn =  tmp;
    }

    ll right;
//    cout<<maxn<<endl;
    if( maxn + 1 >= res)
        right = maxn + 1;
    else
        right = res ;
    right++;
    ll limit = right  + 1  ;
    ll left = maxn - 1;
    cout<<left<<" "<<right<<endl;
    while ( left <  right ){
        ll mid = (left + right ) >> 1;
       // mid  < 0 ? mid = 0xffffffffffffffff : mid = mid;
       change(b, mid ) > 0 && change(b,mid) < res ? left = mid + 1:  right = mid ;
    }


    if( (left == maxn  - 1|| left == limit)  || res != change(b,left)){
        cout<<"Impossible"<<endl;
    }else{
        cout<<left;
    }






    return 0;




}
