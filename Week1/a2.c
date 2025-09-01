#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
int main() {
    int n, a, b;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter two numbers (a and b): ");
    scanf("%d %d", &a, &b);

    int arr[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int pos_a = -1, pos_b = -1;
    int min_dist = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (arr[i] == a) {
            pos_a = i;
            if (pos_b != -1) {
                int dist = abs(pos_a - pos_b);
                if (dist < min_dist) {
                    min_dist = dist;
                }
            }
        }
        else if (arr[i] == b) {
            pos_b = i;
            if (pos_a != -1) {
                int dist = abs(pos_a - pos_b);
                if (dist < min_dist) {
                    min_dist = dist;
                }
            }
        }
    }

    if (min_dist == INT_MAX) {
        printf("Not Found");
    } else {
        printf("Minimum distance between %d and %d is: %d\n", a, b, min_dist);
    }

    return 0;
}
