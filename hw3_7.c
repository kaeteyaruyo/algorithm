#include<stdio.h>
#define N 10

int main(){

    int x[N], d[N][N];
    printf("Sequence length: %d\n", N);
    printf("Enter sequence: ");
    for(int i = 0; i < N; ++i)
        scanf("%d", &x[i]);

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j) d[i][j] = 0;
        for(int j = i; j < N; ++j){
            if(i == j) d[i][j] = x[j];
            else d[i][j] = d[i][j-1] + x[j];
        }
        for(int j = 0; j < N; ++j) printf("%d\t", d[i][j]);;
        printf("\n");
    }

    return 0;

}
