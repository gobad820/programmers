#include <bits/stdc++.h>
int main(int argc, char** argv) {
    int n;
    scanf("%d", &n);

    static bool exist[2000010];
    for(int i = 0 ; i < n ; i++){
        int x;
        scanf("%d", &x);
        exist[x+1000000] = true;
    }

    for(int i = 0 ; i < 2000000; i++){
        if(exist[i]){
            printf("%d\n",i-1000000);
        }
    }
    return 0;
}