// Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

// Input:
// - First line: integer p (number of entries in server log 1)
// - Second line: p sorted integers representing arrival times from server 1
// - Third line: integer q (number of entries in server log 2)
// - Fourth line: q sorted integers representing arrival times from server 2)

// Output:
// - Print a single line containing all arrival times in chronological order, separated by spaces

// Example:
// Input:
// 5
// 10 20 30 50 70
// 4
// 15 25 40 60

// Output:
// 10 15 20 25 30 40 50 60 70

// Explanation: Compare the next unprocessed arrival time from both logs 
// and append the earlier one to the final log until all entries are 
// processed

#include <stdio.h>

int main(){

   int p,q; 

   printf("Enter n0. of entries in server log 1:\n");
   scanf("%d",&p);

   printf("Enter n0. of entries in server log 2:\n");
   scanf("%d",&q);

   int log1[p],log2[q];

   printf("Enter entries of log 1:\n");
   for(int i=0;i<p;i++){
    scanf("%d",&log1[i]);
   }

   printf("Enter entries of log 2:\n");
   for(int i=0;i<q;i++){
    scanf("%d",&log2[i]);
   }

   int log3[p+q];
   for(int k=0;k<p;k++){
    log3[k]=log1[k];
   }
   for(int k=0;k<q;k++){
    log3[p+k]=log2[k];
   }
   for(int i = 0;i <p+q-1; i++) {
        for(int j = 0; j < p+q-i-1; j++) {
            if(log3[j] > log3[j+1]) {
                int temp = log3[j];
                log3[j] = log3[j+1];
                log3[j+1] = temp;
            }
        }
    }
    for(int i=0;i<p+q;i++){
        printf("%d,",log3[i]);
    }



}