#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LEN 50

void shift_element(int* arr, int i){
    int prev=*arr;
    for (int k = 0; k < i; k++){
        arr+=1;
        int curr=*arr;
        *arr=prev;
        prev=curr;
    }   
}

void insertion_sort(int* arr , int len){
    int i, x;
    int *ptr=arr;
    for (int t = 1; t < len; t++){
        i=1;
        x=*ptr;
        while (*(ptr-i)>x && i<=t){
            i+=1;
        }
        i-=1;
        arr=ptr-i;
        shift_element(arr, i);
        *arr=x;
        ptr+=1;
    } 
}

int main(){
    int num=0;
    int arr[LEN];
    int *ptr=arr;
    printf("Please insert array: \n");
    for (int i = 0; i < LEN; i++){
        scanf("%d", &num);
        *(ptr+i)=num;
    }
    ptr+=1;
    insertion_sort(ptr, LEN);
    for (int i = 0; i < LEN; i++){
        if(i==LEN-1){
            printf("%d",*(arr+i));
        }
        else{
            printf("%d,",*(arr+i));
        }
        
    }
    printf("\n");
    return 0;
}




