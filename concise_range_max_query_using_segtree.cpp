#define ll long long
vector<ll> v, Tree;
void buildTree(int ind, int low, int high)
{
    if (low == high)
    {
        Tree[ind] = v[low];
        return;
    }
    int mid = (low + high) >> 1;
    buildTree(2 * ind, low, mid);
    buildTree(2 * ind + 1, mid + 1, high);
    Tree[ind] = max(Tree[2 * ind], Tree[2 * ind + 1]);
}
ll query(int ind, int low, int high, int l, int r)
{
    if (r < low || high < l)
        return LLONG_MIN;
    if (low >= l && high <= r)
        return Tree[ind];
    int mid = (low + high) >> 1;
    ll left = query(2 * ind, low, mid, l, r);
    ll right = query(2 * ind + 1, mid + 1, high, l, r);
    return max(left, right);
}
void update(int ind, int low, int high, int i, ll val)
{
    if (low == high)
    {
        Tree[ind] = val;
        return;
    }
    int mid = (low + high) >> 1;
    if (i <= mid)
        update(2 * ind, low, mid, i, val);
    else
        update(2 * ind + 1, mid + 1, high, i, val);
    Tree[ind] = max(Tree[2 * ind], Tree[2 * ind + 1]);
}
