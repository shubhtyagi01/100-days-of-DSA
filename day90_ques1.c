#include <stdio.h>

int canPaint(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int total = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > maxTime)
            return 0;

        if (total + boards[i] <= maxTime) {
            total += boards[i];
        } else {
            painters++;
            total = boards[i];
        }
    }

    return painters <= k;
}

int minTime(int boards[], int n, int k) {
    int low = 0, high = 0, mid, ans;

    for (int i = 0; i < n; i++) {
        if (boards[i] > low)
            low = boards[i];
        high += boards[i];
    }

    while (low <= high) {
        mid = (low + high) / 2;

        if (canPaint(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    printf("%d", minTime(boards, n, k));

    return 0;
}
