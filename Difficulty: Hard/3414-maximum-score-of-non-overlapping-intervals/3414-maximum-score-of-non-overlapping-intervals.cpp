class Solution {
public:

    struct Node {
        long long score;
        vector<int> ids;
    };

    bool better(const Node& a, const Node& b) {
        if (a.score != b.score)
            return a.score > b.score;

        return a.ids < b.ids;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // {left, right, weight, original index}
        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by LEFT endpoint
        sort(a.begin(), a.end(), [](auto &x, auto &y) {
            if (x[0] != y[0])
                return x[0] < y[0];

            return x[1] < y[1];
        });

        // Store all left endpoints
        vector<long long> starts(n);

        for (int i = 0; i < n; i++)
            starts[i] = a[i][0];

        // next[i] = first interval with left > a[i].right
        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {

            nxt[i] = upper_bound(
                starts.begin(),
                starts.end(),
                a[i][1]
            ) - starts.begin();
        }

        // dp[i][k] = best answer from i onward
        // choosing at most k intervals
        vector<vector<Node>> dp(
            n + 1,
            vector<Node>(5)
        );

        for (int k = 0; k <= 4; k++)
            dp[n][k] = {0, {}};

        for (int i = n - 1; i >= 0; i--) {

            for (int k = 0; k <= 4; k++) {

                // Don't take current interval
                Node best = dp[i + 1][k];

                // Take current interval
                if (k > 0) {

                    Node take = dp[nxt[i]][k - 1];

                    take.score += a[i][2];
                    take.ids.push_back(a[i][3]);

                    sort(take.ids.begin(), take.ids.end());

                    if (better(take, best))
                        best = take;
                }

                dp[i][k] = best;
            }
        }

        return dp[0][4].ids;
    }
};
