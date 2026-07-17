/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    void buildParent(TreeNode* root) {
        if (!root) return;

        if (root->left) {
            parent[root->left] = root;
            buildParent(root->left);
        }

        if (root->right) {
            parent[root->right] = root;
            buildParent(root->right);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildParent(root);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> vis;

        q.push(target);
        vis.insert(target);

        int dist = 0;

        while (!q.empty()) {
            int size = q.size();

            if (dist == k) {
                vector<int> ans;
                while (!q.empty()) {
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left && !vis.count(curr->left)) {
                    vis.insert(curr->left);
                    q.push(curr->left);
                }

                if (curr->right && !vis.count(curr->right)) {
                    vis.insert(curr->right);
                    q.push(curr->right);
                }

                if (parent.count(curr) && !vis.count(parent[curr])) {
                    vis.insert(parent[curr]);
                    q.push(parent[curr]);
                }
            }

            dist++;
        }

        return {};
    }
};