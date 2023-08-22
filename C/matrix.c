#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100

int max(int a, int b, int c) {
    int temp = (a > b) ? a : b;
    return (temp > c) ? temp : c;
}

int maxExperience(int m, int n, int arr[MAX_SIZE][MAX_SIZE]) {
    int dp[MAX_SIZE][MAX_SIZE] = {0};

    // Copy the last row of the input array into dp array as the base case.
    for (int i = 0; i < n; i++) {
        dp[m - 1][i] = arr[m - 1][i];
    }

    // Dynamic programming: calculate the maximum experience value for each cell in dp array.
    for (int i = m - 2; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            int down = dp[i + 1][j];
            int left = (j > 0) ? dp[i][j - 1] : INT_MIN;
            int right = (j < n - 1) ? dp[i][j + 1] : INT_MIN;
            int stay = dp[i][j];

            dp[i][j] = arr[i][j] + max(down, left, right);
        }
    }

    // Find the maximum experience value among all cells in the first row of dp array.
    int maxExperience = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (dp[0][i] > maxExperience) {
            maxExperience = dp[0][i];
        }
    }

    return maxExperience;
}

int main() {
    int m, n;
    printf("Enter the size m and n of the m * n array: ");
    scanf("%d %d", &m, &n);

    int arr[MAX_SIZE][MAX_SIZE];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int result = maxExperience(m, n, arr);
    printf("The maximum experience value is: %d\n", result);

    return 0;
}
