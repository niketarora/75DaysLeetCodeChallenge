#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk;
        int maxArea = 0;
        
        // Iterate through all bars, including one extra 0-height bar to
        // clear the stack at the end.
        for (int i = 0; i <= n; ++i) {
            // Use 0 if we've gone past the last bar, otherwise use actual height
            int currentHeight = (i == n) ? 0 : heights[i];
            
            // If current bar is shorter than the stack top, pop and calculate
            while (!stk.empty() && heights[stk.top()] >= currentHeight) {
                int height = heights[stk.top()];
                stk.pop();
                
                // Determine width: if stack is empty, it means this bar was
                // the minimum so far, so width goes from 0 to i.
                int width = stk.empty() ? i : i - stk.top() - 1;
                
                maxArea = max(maxArea, height * width);
            }
            stk.push(i);
        }
        
        return maxArea;
    }
};
