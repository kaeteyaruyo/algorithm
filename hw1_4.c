#include<stdio.h>

int merge_count = 0;
int bubble_count = 0;

void merge_sort(int arr[], int reg[], int l, int r);
void bubble_sort(int arr[], int n);
void print(int arr[], int n);

int main(){

    int N,i;

    printf("Enter sequence length: ");
    scanf("%d", &N);

    int arr[N], arr1[N], reg[N];
    printf("Enter sequence: ");
    for(i = 0; i < N; ++i){
        scanf("%d", &arr[i]);
        arr1[i] = arr[i];
    }

    print(arr,N);
    merge_sort(arr,reg,0,N-1);
    print(arr,N);

    bubble_sort(arr1,N);
    print(arr1,N);

    printf("merge: %d\nbubble: %d\n",merge_count, bubble_count);
    return 0;

}

void merge_sort(int arr[], int reg[], int l, int r){

    if(l>=r) return;

    int m = (l+r)/2;
    merge_sort(arr,reg,l,m);
    merge_sort(arr,reg,m+1,r);

    int i = l, j = m+1, k = l;
    while(i <= m && j <= r){
        if(arr[i] < arr[j]){
            reg[k++] = arr[i++];
        }
        else{
            reg[k++] = arr[j++];
            merge_count += m - i + 1;
        }
    }

    while(i <= m) reg[k++] = arr[i++];
    while(j <= r) reg[k++] = arr[j++];
    for(k = l; k <= r; ++k) arr[k] = reg[k];

}

void bubble_sort(int arr[], int n){

    int i,j;
    for(i = 0; i < n - 1; ++i){
        for(j = 0; j < n - 1 - i; ++j){
            if(arr[j] > arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                bubble_count++;
            }
        }
    }

}

void print(int arr[], int n){

    int i;
    for(i = 0; i < n; ++i) printf("%d ", arr[i]);
    printf("\n");

}
