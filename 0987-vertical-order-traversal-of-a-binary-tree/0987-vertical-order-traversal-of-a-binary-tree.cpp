/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<tuple<int,int,int>> nodes;

    void dfs(TreeNode* root, int row, int col) {
        if (!root) return;

        nodes.push_back({col, row, root->val});

        dfs(root->left, row + 1, col - 1);
        dfs(root->right, row + 1, col + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);

        sort(nodes.begin(), nodes.end());

        vector<vector<int>> ans;

        int prevCol = INT_MIN;

        for (auto &t : nodes) {
            int col = get<0>(t);
            int val = get<2>(t);

            if (col != prevCol) {
                ans.push_back({});
                prevCol = col;
            }

            ans.back().push_back(val);
        }

        return ans;
    }
};