#include<iostream>
#include<climits>
using namespace std;
const int N = 100000;
int t[N];
int size = 0;
void insert(int x){
    int i;
    for(i = ++size; t[i/2] > x; i = i /2){
        t[i] = t[i/2];
    }
    t[i] = x;

}

int deleteTop(){
    if(size == 0)
        return -1;
    int top = t[1];
    int last = t[size--];
    int child , i;
    for( i=1; i*2 <= size;  i = child){
        child = i * 2;
        if(child != size && t[child + 1] < t[child])
            child = child + 1;
        if( last > t[child])
            t[i] = t[child];
        else
            break;
    }
    t[i] = last;
    return top;
}


int main()
{
    t[0] = INT_MIN;
    int n;
    cin>>n;
    for(int i=0; i<n; ++i){
        int t;
        cin>>t;
        insert(t);
    }
    for(int i=0; i<n; ++i)
        cout<<deleteTop()<<endl;

}
