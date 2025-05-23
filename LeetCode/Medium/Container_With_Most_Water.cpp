// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.

// Example 1:

// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

// Example 2:

// Input: height = [1,1]
// Output: 1
 
// Constraints:

// n == height.length
// 2 <= n <= 105
// 0 <= height[i] <= 104

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int answer = 0;
        int si = 0;
        int ei = height.size() - 1;

        while (si < ei) {
            int w = ei - si;
            int h = min(height[si], height[ei]);
            answer = max(answer, w * h);

            if (height[si] > height[ei]) ei--;
            else si++;
        }

        return answer;
    }
};

int main() {
    // g.
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    Solution s;
    int answer = s.maxArea(height);
    cout << "answer: " << answer << endl;

    return 0;
}

/**
 * Runtime: 0ms 100.00%
 * Memory: 62.84MB 78.74%
 */