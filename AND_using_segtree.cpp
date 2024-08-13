// 3209. Number of Subarrays With AND Value of K
// https://leetcode.com/submissions/detail/1344411639/
void build(int i, int low, int high, vector<int> &seg, vector<int> &arr)
{
    if (low > high)
        return;
    if (low == high)
    {
        seg[i] = arr[low];
        return;
    }
    int mid = (low + high) >> 1;
    build(2 * i + 1, low, mid, seg, arr);
    build(2 * i + 2, mid + 1, high, seg, arr);
    seg[i] = seg[2 * i + 1] & seg[2 * i + 2];
}

int query(int i, int low, int high, int l, int r, vector<int> &seg)
{
    if (low >= l && high <= r)
        return seg[i];
    if (low > r || high < l || low > high)
        return -1;
    int mid = (low + high) >> 1;
    int left = query(2 * i + 1, low, mid, l, r, seg);
    int right = query(2 * i + 2, mid + 1, high, l, r, seg);
    return left & right;
}

void update(int i, int low, int high, int idx, int value, vector<int> &seg)
{
    if (low == high)
    {
        seg[i] = value;
        return;
    }
    int mid = (low + high) >> 1;
    if (idx <= mid)
    {
        update(2 * i + 1, low, mid, idx, value, seg);
    }
    else
    {
        update(2 * i + 2, mid + 1, high, idx, value, seg);
    }
    seg[i] = seg[2 * i + 1] & seg[2 * i + 2];
}