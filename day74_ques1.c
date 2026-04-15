#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char names[n][50];      // input names
    char unique[n][50];     // unique candidate names
    int count[n];           // vote count

    int uniqueCount = 0;

    // Initialize count array
    for(int i = 0; i < n; i++) {
        count[i] = 0;
    }

    // Input names
    for(int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    // Count votes
    for(int i = 0; i < n; i++) {
        int found = 0;

        for(int j = 0; j < uniqueCount; j++) {
            if(strcmp(names[i], unique[j]) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }

        if(!found) {
            strcpy(unique[uniqueCount], names[i]);
            count[uniqueCount] = 1;
            uniqueCount++;
        }
    }

    // Find winner
    int maxVotes = count[0];
    char winner[50];
    strcpy(winner, unique[0]);

    for(int i = 1; i < uniqueCount; i++) {
        if(count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, unique[i]);
        }
        else if(count[i] == maxVotes) {
            if(strcmp(unique[i], winner) < 0) {
                strcpy(winner, unique[i]);
            }
        }
    }

    // Output result
    printf("%s %d\n", winner, maxVotes);

    return 0;
}
