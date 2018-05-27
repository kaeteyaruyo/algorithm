#include<stdio.h>
#define M 1000
#define N 10
#define max(x,y) (x > y ? x : y)

typedef struct{ int charm, price; } item;

int m = M;
int n = N;
item list[N];
int dpTable[M+1];

int knapsack(int number, int money);

int main(){

    printf("Marry has %d money. Enter %d pairs of charm and price of jewerly:\n", m, n);
    for(int i = 0; i < n; ++i)
        scanf("%d %d", &list[i].charm, &list[i].price);

    printf("Max sum of charm: %d\n", knapsack(n, m));

    return 0;

}

int knapsack(int number, int money){

    for(int i = 0; i < number; ++i){
        int price = list[i].price;
        int charm = list[i].charm;
        for(int j = money; j - price >= 0; --j)
            dpTable[j] = max(dpTable[j], dpTable[j - price] + charm);
    }

    return dpTable[money];

}
