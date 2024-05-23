#include <stdlib.h> 
#include <stdio.h>

int *ellementizer(long long NumT, int *plen);
int rewriter(int arr[], int len);
long long numberizer(int len, int arr[], long long n);
int *append(int *arr, int len, int elem);

long long next_bigger_number(long long n) {
     long long NumT;
    NumT = n;
    int len = 0;
    int *plen = &len;
    int *arr = ellementizer(NumT, plen); 
    int c =0;
    c = rewriter(arr, len); 
    if(c == -1) {
        //printf("-1");
        return -1;
    }
    else {
    n = numberizer(len, arr, n);  
    }
    free(arr); 
    return n;
}


int* ellementizer(long long NumT, int* plen) {
    int len = 0;
    int* arrw = NULL;
    // Calculate the length required for the array
    long long tmp = NumT;
    while (tmp != 0) {
        tmp = tmp / 10;
        len++;
    }
    // Allocate memory for the array
    arrw = (int*)malloc(len * sizeof(int));
    if (arrw == NULL) {
        // Handle memory allocation failure
        *plen = 0;
        return NULL;
    }
    // Fill the array with digits of NumT
    for (int i = 0; i < len; i++) {
        arrw[len - i - 1] = NumT % 10;
        NumT = NumT / 10;
    }
    // Update the length through the pointer
    *plen = len;
    return arrw;
}

int rewriter(int arr[], int len) {
    int barrier=len-2;
    int timer=0;
    int tmp=0;
    if(barrier==-1){
        return -1;
    }
    while(arr[barrier]>=arr[barrier+1]){
        barrier=barrier-1;
        timer=timer+1;
        if(barrier==-1){
            return -1;
        }
    }
    for(int repeat_counter=1;repeat_counter<=timer;repeat_counter++){
        int swaper1=len-2;
        int swaper2=len-1;
        for(int swap_counter=1;swap_counter<=timer;swap_counter++){
            if(arr[swaper1]>arr[swaper2]){
                tmp=arr[swaper1];
                arr[swaper1]=arr[swaper2];
                arr[swaper2]=tmp;
            }
            swaper1=swaper1-1;
            swaper2=swaper2-1;
        }
    }
    int bigger=barrier;
    for(int i=1; i<=timer+1; i++){
        bigger=bigger+1;
        if(arr[barrier]<arr[bigger]){
            tmp=arr[barrier];
            arr[barrier]=arr[bigger];
            arr[bigger]=tmp;
            break;
        }
    }
    return 0;
}

long long numberizer(int plen, int arr[], long long n) {
    int len = plen;
    n = 0;
    int i = 0;
    for (;i < len;) {
        n = n * 10 + arr[i];
        i=i+1;
    }
    //printf("%ld\n", n);
    return n;
}