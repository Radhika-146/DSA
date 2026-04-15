/*Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.

Output Format
Print the name of the winning candidate followed by the number of votes received.

Sample Input
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

Sample Output
john 4

Explanation
Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.*/

code:

#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char names[1000][50];
    int count[1000] = {0};
    int unique = 0;

    for(int i = 0; i < n; i++) {
        char temp[50];
        scanf("%s", temp);

        int found = -1;
        for(int j = 0; j < unique; j++) {
            if(strcmp(names[j], temp) == 0) {
                found = j;
                break;
            }
        }

        if(found != -1) {
            count[found]++;
        } else {
            strcpy(names[unique], temp);
            count[unique] = 1;
            unique++;
        }
    }

    int max = count[0];
    char winner[50];
    strcpy(winner, names[0]);

    for(int i = 1; i < unique; i++) {
        if(count[i] > max || (count[i] == max && strcmp(names[i], winner) < 0)) {
            max = count[i];
            strcpy(winner, names[i]);
        }
    }

    printf("%s %d", winner, max);

    return 0;
}
