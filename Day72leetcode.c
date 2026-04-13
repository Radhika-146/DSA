/*Given a 2d matrix cost[][] of size n where cost[i][j] denotes the cost of moving from city i to city j. Your task is to complete a tour from city 0 (0-based index) to all other cities such that you visit each city exactly once and then at the end come back to city 0 at minimum cost.*/



code:
#include <stdio.h>
#include <limits.h>

int n;

int min(int a, int b) {
    return a < b ? a : b;
}

int tsp(int mask, int pos, int cost[20][20], int dp[1<<20][20]) {
    if (mask == (1 << n) - 1)
        return cost[pos][0];

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;

    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = cost[pos][city] + tsp(mask | (1 << city), city, cost, dp);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    scanf("%d", &n);
    int cost[20][20];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    static int dp[1<<20][20];

    for (int i = 0; i < (1<<n); i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;

    printf("%d", tsp(1, 0, cost, dp));
    return 0;
}
