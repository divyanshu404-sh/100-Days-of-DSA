// Problem: Read a string and check if it is a palindrome using two-pointer comparison.

// Input:
// - Single line: string s

// Output:
// - Print YES if palindrome, otherwise NO

// Example:
// Input:
// level

// Output:
// YES

// Explanation: String reads same forwards and backwards

#include <stdio.h>
#include <string.h>

int main(){

    char str[50];

    printf("Enter string:\n");
    scanf("%s",str);
    int k=strlen(str);
    int flag = 0;
    for(int i=0;i<k/2;i++){
        if(str[i] != str[k-i-1]){
            flag = 1;
        }
    }
    if(flag == 1){
        printf("NOT PALINDROME\n");
    }
    else{
        printf("PALINDROME\n");
    }
}