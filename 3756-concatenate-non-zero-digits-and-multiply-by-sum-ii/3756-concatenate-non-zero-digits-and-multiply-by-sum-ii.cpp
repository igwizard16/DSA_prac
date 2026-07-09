class Solution {
    const long long MOD = 1e9 + 7;

    struct Node { long long val; int cnt; };

    vector<Node> segTree;
    vector<long long> pw;
    string str;

    Node merge(const Node& left, const Node& right) {
        return { (left.val * pw[right.cnt] + right.val) % MOD, left.cnt + right.cnt };
    }

    void build(int node, int l, int r) {
        if (l == r) {
            int digit = str[l] - '0';
            segTree[node] = digit ? Node{digit, 1} : Node{0, 0};
            return;
        }
        int mid = (l + r) / 2;
        build(2*node, l, mid);
        build(2*node+1, mid+1, r);
        segTree[node] = merge(segTree[2*node], segTree[2*node+1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return {0, 0};              // no overlap -> identity
        if (ql <= l && r <= qr) return segTree[node];      // fully inside -> stored value
        int mid = (l + r) / 2;
        Node leftRes  = query(2*node,   l,     mid, ql, qr);
        Node rightRes = query(2*node+1, mid+1, r,   ql, qr);
        return merge(leftRes, rightRes);
    }

public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        str = s;
        int n = s.size();
        segTree.assign(4*n, Node{0,0});
        pw.assign(n+1, 1);
        for (int i = 1; i <= n; i++) pw[i] = (pw[i-1] * 10) % MOD;

        build(1, 0, n-1);

        vector<long long> digitPrefixSum(n+1, 0);
        for (int i = 0; i < n; i++){
            digitPrefixSum[i+1] = digitPrefixSum[i] + (s[i] - '0');
        }

        vector<int> ans;
        ans.reserve(queries.size());
        
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            Node res = query(1, 0, n-1, l, r);
            long long sum = digitPrefixSum[r+1] - digitPrefixSum[l];
            ans.push_back((res.val * (sum % MOD)) % MOD);
        }
        return ans;
    }
};