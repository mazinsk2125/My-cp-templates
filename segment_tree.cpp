#define ll long long
#define int long long

void buildSegmentTree(int i, int l, int r, vector<int>& segmentTree, int arr[]) {
    if (l == r) {
        segmentTree[i] = arr[l];
        return;
    }
    int mid = l + (r - l) / 2;
    buildSegmentTree(2 * i + 1, l, mid, segmentTree, arr);
    buildSegmentTree(2 * i + 2, mid + 1, r, segmentTree, arr);
    segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
}
 
int querySegmentTree(int start, int end, int i, int l, int r, vector<int>& segmentTree) {
    if (l > end || start > r) {
        return 0;
    }
    if (l >= start && r <= end) {
        return segmentTree[i];
    }
    int mid = l + (r - l) / 2;
    return querySegmentTree(start, end, 2 * i + 1, l, mid, segmentTree) +
           querySegmentTree(start, end, 2 * i + 2, mid + 1, r, segmentTree);
}
 
void updateSegmentTree(int i, int l, int r, int idx, int value, vector<int>& segmentTree) {
    if (l == r) {
        segmentTree[i] += value;  // Increment the value
        return;
    }
    int mid = l + (r - l) / 2;
    if (idx <= mid) {
        updateSegmentTree(2 * i + 1, l, mid, idx, value, segmentTree);
    } else {
        updateSegmentTree(2 * i + 2, mid + 1, r, idx, value, segmentTree);
    }
    segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
}


class RangeSumQuery
{
public:
    vector<ll> seg;

    RangeSumQuery(int n)
    {
        seg.resize(4 * n + 1);
    }

    void build(int ind, int low, int high, vector<ll> &arr)
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }

        int mid = (low + high) >> 1;

        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);

        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    ll query(int ind, int low, int high, int l, int r)
    {
        if (r < low || high < l)
            return 0;

        if (low >= l && high <= r)
            return seg[ind];

        int mid = (low + high) >> 1;
        ll left = query(2 * ind + 1, low, mid, l, r);
        ll right = query(2 * ind + 2, mid + 1, high, l, r);

        return left + right;
    }

    void update(int ind, int low, int high, int i, ll val)
    {
        if (low == high)
        {
            seg[ind] = val;
            return;
        }

        int mid = (low + high) >> 1;

        if (i <= mid)
            update(2 * ind + 1, low, mid, i, val);
        else
            update(2 * ind + 2, mid + 1, high, i, val);

        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
};




#define ll long long

class RangeMinQuery
{
public:
    vector<ll> seg;

    RangeMinQuery(int n)
    {
        seg.resize(4 * n + 1, LLONG_MAX);
    }

    void build(int ind, int low, int high, vector<ll> &arr)
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }

        int mid = (low + high) >> 1;

        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);

        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    ll query(int ind, int low, int high, int l, int r)
    {
        if (r < low || high < l)
            return LLONG_MAX;

        if (low >= l && high <= r)
            return seg[ind];

        int mid = (low + high) >> 1;
        ll left = query(2 * ind + 1, low, mid, l, r);
        ll right = query(2 * ind + 2, mid + 1, high, l, r);

        return min(left, right);
    }

    void update(int ind, int low, int high, int i, ll val)
    {
        if (low == high)
        {
            seg[ind] = val;
            return;
        }

        int mid = (low + high) >> 1;

        if (i <= mid)
            update(2 * ind + 1, low, mid, i, val);
        else
            update(2 * ind + 2, mid + 1, high, i, val);

        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};

#define ll long long

class RangeMaxQuery
{
public:
    vector<ll> seg;

    RangeMaxQuery(int n)
    {
        seg.resize(4 * n + 1, LLONG_MIN);
    }

    void build(int ind, int low, int high, vector<ll> &arr)
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }

        int mid = (low + high) >> 1;

        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);

        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    ll query(int ind, int low, int high, int l, int r)
    {
        if (r < low || high < l)
            return LLONG_MIN;

        if (low >= l && high <= r)
            return seg[ind];

        int mid = (low + high) >> 1;
        ll left = query(2 * ind + 1, low, mid, l, r);
        ll right = query(2 * ind + 2, mid + 1, high, l, r);

        return max(left, right);
    }

    void update(int ind, int low, int high, int i, ll val)
    {
        if (low == high)
        {
            seg[ind] = val;
            return;
        }

        int mid = (low + high) >> 1;

        if (i <= mid)
            update(2 * ind + 1, low, mid, i, val);
        else
            update(2 * ind + 2, mid + 1, high, i, val);

        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};
