using ll = long long;
class Solution
{
public:
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
    ll numberOfSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        v = vector<ll>(nums.begin(), nums.end());
        vector<ll> dp(n, 1);
        map<int, int> mp;
        Tree.resize(4 * n + 5);
        buildTree(1, 0, n - 1);
        mp[nums[0]] = 0;
        for (int i = 1; i < n; i++)
        {
            if (mp.find(nums[i]) == mp.end())
            {
                mp[nums[i]] = i;
                continue;
            }
            int maxi = query(1, 0, n - 1, mp[nums[i]], i);
            if (maxi == nums[i])
                dp[i] += dp[mp[nums[i]]];
            mp[nums[i]] = i;
        }
        return accumulate(begin(dp), end(dp), 0ll);
    }
};
// https://leetcode.com/problems/find-the-number-of-subarrays-where-boundary-elements-are-maximum/
// Here dp is used the store the number of subarrays ending at index which satisfy
// the condition given in the question
// initiall it will n 1's