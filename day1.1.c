// # Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

// # Input:
// # - First line: integer n
// # - Second line: n space-separated integers (the array)
// # - Third line: integer pos (1-based position)
// # - Fourth line: integer x (element to insert)

// # Output:
// # - Print the updated array (n+1 integers) in a single line, space-separated

// # Example:
// # Input:
// # 5
// # 1 2 4 5 6
// # 3
// # 3

// # Output:
// # 1 2 3 4 5 6

// # Explanation: Insert 3 at position 3, elements [4,5,6] shift right

#include <stdio.h>

int main(){

    int n,m,k;

    printf("Enter no. of elements: \n");
    scanf("%d",&n);
    int arr[n+1];
    
    printf("Enter elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    arr[n]=0;
    printf("Enter position to insert at:\n");
    scanf("%d",&m);
    printf("Enter element to insert:\n");
    scanf("%d",&k);

    for(int i=n;i>=m;i--){
        arr[i]=arr[i-1];
    }
    arr[m-1]=k;

    for(int i=0;i<=n;i++){
        printf("%d,",arr[i]);
    }

    return 0;

}