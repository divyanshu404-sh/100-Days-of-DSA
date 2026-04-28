//Write a program to take an integer array nums of size n, and print the majority element. 
//The majority element is the element that appears strictly more than ⌊n / 2⌋ times. Print -1 
//if no such element exists. Note: Majority Element is not necessarily the element that is present 
//most number of times.

#include <stdio.h>

int main(){

    int n;

    printf("Enter no. of elements\n");
    scanf("%d",&n);

    int nums[n];

    printf("Enter elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    
    int major=-1;

    for(int i=0;i<n;i++){
        int k=0;
        for(int j=0;j<n;j++){
            if(nums[i]==nums[j]){
                k++;
            }
            }
            if(k>n/2){
                major=nums[i];
                break;
        }
    }
    printf("%d\n",major);
    return 0;
}