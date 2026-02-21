// Problem: Given an array of integers, find two elements whose sum is closest to zero.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the pair of elements whose sum is closest to zero

// Example:
// Input:
// 5
// 1 60 -10 70 -80

// Output:
// -10 1

// Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.


#include <stdio.h>

int main(){

    int n;

    printf("Enter size of array:\n");
    scanf("%d",&n);

    int arr[n];
    
    printf("Enter elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
int a=999,b,c,d;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((arr[i]+arr[j])<0){
                b=(0-(arr[i]+arr[j]));
            }
            else{
                b = arr[i]+arr[j];
            }
            if(a>b){
                a=b;
                c=i;
                d=j;
            }
        }
    }
    printf("%d %d\n",arr[c],arr[d]);
}