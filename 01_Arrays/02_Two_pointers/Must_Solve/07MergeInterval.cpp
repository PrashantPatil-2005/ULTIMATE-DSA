#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // Time Complexity: O(N * log N) due to sorting
    // Space Complexity: O(N) for storing the result

    vector<vector<int>> merged;

    if (intervals.empty()) return merged;

    // Step 1: Sort the intervals based on starting times
    sort(intervals.begin(), intervals.end());

    // Step 2: Initialize the first interval
    vector<int> current = intervals[0];

    for (int i = 1; i < intervals.size(); ++i) {
        // If intervals overlap, merge them
        if (current[1] >= intervals[i][0]) {
            current[1] = max(current[1], intervals[i][1]);
        } else {
            // No overlap, push current to result and update current
            merged.push_back(current);
            current = intervals[i];
        }
    }

    // Add the last interval
    merged.push_back(current);
    return merged;
}

int main() {
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int>> result = merge(intervals);

    cout << "Merged Intervals:\n";
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "]\n";
    }

    return 0;
}
