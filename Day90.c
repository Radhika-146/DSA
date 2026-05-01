/*Problem Statement
Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

Determine the minimum time required to paint all boards.

Input Format
n k
n space-separated integers representing board lengths

Output Format
Print the minimum time required to paint all boards.

Sample Input
4 2
10 20 30 40

Sample Output
60

Explanation
One painter paints boards of length 10, 20, and 30 (total 60), while the other paints board of length 40.*/

code:


#include <stdio.h>

int isPossible(int boards[], int n, int k, int mid) {
    int painters = 1, total = 0;
    for (int i = 0; i < n; i++) {
        if (boards[i] > mid) return 0;
        if (total + boards[i] > mid) {
            painters++;
            total = boards[i];
            if (painters > k) return 0;
        } else {
            total += boards[i];
        }
    }
    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int boards[n];
    int sum = 0, maxVal = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        sum += boards[i];
        if (boards[i] > maxVal) maxVal = boards[i];
    }
    int lo = maxVal, hi = sum, ans = sum;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (isPossible(boards, n, k, mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
