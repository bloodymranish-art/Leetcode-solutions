class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int i = 0;
        int j = n - 1;
        int ans = n;

        // Binary Search: first element >= x
        while (i <= j) {
            int mid = i + (j - i) / 2;

            if (arr[mid] >= x) {
                ans = mid;
                j = mid - 1;
            }
            else {
                i = mid + 1;
            }
        }

        // Expand around the insertion position
        int left = ans - 1;
        int right = ans;

        while (k > 0) {
            if (left < 0) {
                right++;
            }
            else if (right >= n) {
                left--;
            }
            else if (abs(arr[left] - x) <= abs(arr[right] - x)) {
                left--;
            }
            else {
                right++;
            }
            k--;
        }

        // Collect the selected elements in sorted order
        vector<int> res;

        for (int idx = left + 1; idx < right; idx++) {
            res.push_back(arr[idx]);
        }

        return res;
    }
};