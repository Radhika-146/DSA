/*Problem: Given intervals, merge all overlapping ones.
Sort first, then compare with previous.*/

code:

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

int cmp(const void *a, const void *b) {
    Interval *x = (Interval *)a;
    Interval *y = (Interval *)b;
    return x->start - y->start;
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].start, &arr[i].end);

    qsort(arr, n, sizeof(Interval), cmp);

    Interval res[n];
    int k = 0;

    res[k] = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i].start <= res[k].end) {
            if (arr[i].end > res[k].end)
                res[k].end = arr[i].end;
        } else {
            k++;
            res[k] = arr[i];
        }
    }

    for (int i = 0; i <= k; i++)
        printf("%d %d\n", res[i].start, res[i].end);

    return 0;
}
