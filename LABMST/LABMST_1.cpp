#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = 0;

    for(int i = 0; i < 32; i++) {
        int count = 0;

        for(int j = 0; j < nums.size(); j++) {
            if(nums[j] & (1 << i))
                count++;
        }

        if(count % 3 != 0)
            ans |= (1 << i);
    }

    return ans;
}

int main() {
    vector<int> nums = {2,2,3,2};
    cout << singleNumber(nums);
}
