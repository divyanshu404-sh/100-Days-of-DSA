// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
// Example 2:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.

#include <stdio.h>

int main(){

    int n;

    printf("Enter number of days:\n");
    scanf("%d",&n);
    
    int prices[n+1];

    printf("Enter prices on each day:\n");
    for(int i=1;i<n+1;i++){
        scanf("%d",&prices[i]);
    }
    int k=0,profit=0;
    for(int i=1;i<n+1;i++){
        for(int j=i+1;j<n+1;j++){
            if(prices[j]>prices[i]){
                k=prices[j]-prices[i];
            }
            if(profit<k){
                profit = k; 
            }
        }
    }
    printf("%d\n",profit);
}