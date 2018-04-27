/*****************************************
** Show how to sort n integers          **
** in the range 0 to n^2-1 in O(n) time,**
** but the space complexity is in O(n)  **
*****************************************/
#include<cstdio>
#include<cmath>
#define n 10
#define number_of_digit 2

using namespace std;

typedef struct { short int digit[number_of_digit]; } word;
word input[n];
int output[n];
void count_sort(word init[], short int d);

int main(){

    int i;
    word input[n];

    printf("Input size: %d\n", n);
    printf("Enter %d integers in 0 ~ %d: ", n, (int)(pow(n,number_of_digit)-1));

    // get inputs and change them into n base numbers
    for(i = 0; i < n; ++i){
        int temp;
        scanf("%d", &temp);
        if(temp >= pow(n,number_of_digit)){
            printf("Exceed range.\n");
            return 0;
        }
        for(int j = 0; j < number_of_digit; ++j)
            input[i].digit[j] = (temp / (int)pow(n,j)) % n;
    }

    // radix sort using counting sort
    for(i = 0; i < number_of_digit; ++i)
        count_sort(input, i);

    // print 
    printf("Sorted: ");
    for(i = 0; i < n; ++i){
        output[i] = 0;
        for(int j = 0; j < number_of_digit; ++j)
            output[i] += input[i].digit[j] * (int)pow(n, j);
        printf("%d ", output[i]);
    }
    printf("\n");

    return 0;

}

void count_sort(word init[], short int d){

    word done[n];
    int i, j, k, count_arr[n];

	for (k = 0; k < n; k++)
		count_arr[k] = 0;
	for (i = 0; i < n; i++){
		count_arr[init[i].digit[d]]++;
    }
	for (k = 1; k < n; k++)
		count_arr[k] += count_arr[k - 1];
	for (j = n; j > 0; j--)
		done[--count_arr[init[j - 1].digit[d]]] = init[j - 1];
    for (i = 0; i < n; i++)
        init[i] = done[i];

}
