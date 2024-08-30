// https : // www.geeksforgeeks.org/problems/lcs-of-three-strings0028/1
// Given 3 strings A, B and C, the task is to find the length of the longest sub-sequence that is common in all the three given strings.
//standard template tabulation dp
// Example 1:

// Input:
// A = "geeks"
// B = "geeksfor",
// C = "geeksforgeeks"
// Output: 5
// Explanation:
// "geeks"is the longest common
// subsequence with length 5.
class Solution
{
public:
    int LCSof3(string A, string B, string C, int n1, int n2, int n3)
    {
        vector<vector<vector<int>>> dp(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(n3 + 1, 0)));
        int ans = 0;

        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                for (int k = 1; k <= n3; k++)
                {
                    if (A[i - 1] == B[j - 1] && B[j - 1] == C[k - 1])
                    {
                        dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                    }
                    else
                    {
                        dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                    }
                    ans = max(ans, dp[i][j][k]);
                }
            }
        }

        return ans;
    }
};
