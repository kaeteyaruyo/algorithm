/*****************************************
** Show how to sort n integers          **
** in the range 0 to n^2-1 in O(n) time,**
** but the space complexity is in O(n)  **
*****************************************/
#include<cstdio>
#include<vector>
#define n 10
using namespace std;

int input[n];
vector<int> bucket[n];

void count_sort(vector<int> &v);

int main(){

    int i;
    vector<int>::iterator it;

    printf("Input size: %d\n", n);
    printf("Enter %d integers in 0 ~ %d: ", n, n*n-1);

    // get inputs
    for(i = 0; i < n; ++i){
        int temp;
        scanf("%d", &temp);
        if(temp >= n*n){
            printf("Exceed range.\n");
            return 0;
        }
        input[i] = temp;
    }

    // classify inputs into buckets
    for(i = 0; i < n; ++i)
        bucket[input[i] / n].push_back(input[i]);

    // sort each bucket using count sort
    for(i = 0; i < n; ++i)
        count_sort(bucket[i]);

    // cobine each sorted bucket
    for(i = 1; i < n; ++i){
        for(it = bucket[i].begin(); it != bucket[i].end(); it++)
            bucket[0].push_back(*it);
        bucket[i].clear();
    }

    // print 
    printf("Sorted: ");
    for(it = bucket[0].begin(); it != bucket[0].end(); it++)
        printf("%d ", *it);
    printf("\n");

    return 0;

}

void count_sort(vector<int> &v){

    vector<int> done;
    int i, j, k, count_arr[n];

	for (k = 0; k < n; k++)
		count_arr[k] = 0;
	for (i = 0; i < v.size(); i++){
		count_arr[v[i] % n]++;
        done.push_back(0);
    }
	for (k = 1; k < n; k++)
		count_arr[k] += count_arr[k - 1];
	for (j = v.size(); j > 0; j--)
		done[--count_arr[v[j - 1] % n]] = v[j - 1];
    for (i = 0; i < v.size(); i++)
        v[i] = done[i];

}
