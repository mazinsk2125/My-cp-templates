// https : // leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/description/
class Solution
{
private:
    void buildSegmentTree(int i, int l, int r, vector<int> &segmentTree, vector<int> &arr)
    {
        if (l == r)
        {
            segmentTree[i] = arr[l];
            return;
        }
        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, segmentTree, arr);
        buildSegmentTree(2 * i + 2, mid + 1, r, segmentTree, arr);
        segmentTree[i] = segmentTree[2 * i + 1] & segmentTree[2 * i + 2];
    }

    int querySegmentTree(int start, int end, int i, int l, int r, std::vector<int> &segmentTree)
    {
        if (l > end || start > r)
        {
            return -1;
        }
        if (l >= start && r <= end)
        {
            return segmentTree[i];
        }
        int mid = l + (r - l) / 2;
        return querySegmentTree(start, end, 2 * i + 1, l, mid, segmentTree) & querySegmentTree(start, end, 2 * i + 2, mid + 1, r, segmentTree);
    }

public:
    int closestToTarget(vector<int> &arr, int target)
    {
        int n = (int)arr.size();
        vector<int> segmentTree(4 * n, 0);
        buildSegmentTree(0, 0, n - 1, segmentTree, arr);
        int ans = 1e9;
        int mini = abs(arr[0] - target);
        for (int i = 0; i < n; ++i)
        {
            int low = i, high = n - 1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                int currentAND = querySegmentTree(i, mid, 0, 0, n - 1, segmentTree);
                if (currentAND > target)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
                ans = min(ans, abs(target - currentAND));
            }
        }
        return ans;
    }
};
