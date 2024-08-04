// https://leetcode.com/submissions/detail/1344403122/
// used in leetcode question 3171. Find Subarray With Bitwise OR Closest to K
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
    segmentTree[i] = segmentTree[2 * i + 1] | segmentTree[2 * i + 2];
}

int querySegmentTree(int start, int end, int i, int l, int r, vector<int> &segmentTree)
{
    if (l > end || start > r)
    {
        return 0;
    }
    if (l >= start && r <= end)
    {
        return segmentTree[i];
    }
    int mid = l + (r - l) / 2;
    return querySegmentTree(start, end, 2 * i + 1, l, mid, segmentTree) |
           querySegmentTree(start, end, 2 * i + 2, mid + 1, r, segmentTree);
}

void updateSegmentTree(int i, int l, int r, int idx, int value, vector<int> &segmentTree)
{
    if (l == r)
    {
        segmentTree[i] = value;
        return;
    }
    int mid = l + (r - l) / 2;
    if (idx <= mid)
    {
        updateSegmentTree(2 * i + 1, l, mid, idx, value, segmentTree);
    }
    else
    {
        updateSegmentTree(2 * i + 2, mid + 1, r, idx, value, segmentTree);
    }
    segmentTree[i] = segmentTree[2 * i + 1] | segmentTree[2 * i + 2];
}
