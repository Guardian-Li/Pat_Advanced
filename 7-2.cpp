#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int main()
{
    int n;

    int flag = 1;
    int index;
    int x;
    while(scanf("%d %d",&x,&index)!= EOF){



        if(index == 0)
            continue;
        x = x*index;
        index = index - 1;
        if(!flag)
            printf(" ");
        printf("%d %d",x,index);

        flag = 0;
    }
    if(flag)
        printf("0 0");
    return 0;


}
