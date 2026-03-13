#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());

        int left = 0;
        int right = tokens.size() - 1;
        int score = 0;
        int maxScore = 0;

        while (left <= right) {
            if (power >= tokens[left]) {
                power -= tokens[left];
                score++;
                left++;
                maxScore = max(maxScore, score);
            }
            else if (score > 0) {
                power += tokens[right];
                score--;
                right--;
            }
            else {
                break;
            }
        }

        return maxScore;
    }
};

int main() {
    vector<int> tokens = {100};
    int power = 50;

    Solution obj;
    cout << obj.bagOfTokensScore(tokens, power);

    return 0;
}