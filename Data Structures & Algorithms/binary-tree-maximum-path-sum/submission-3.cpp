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
private:
    int result = -INT_MAX;
    std::unordered_map<TreeNode*, int> max_propogate;

    void dfs(TreeNode* root, int sum = 0)
    {
        if(!root)
            return;

        sum += root->val;

        dfs(root->left, sum);
        dfs(root->right, sum);
        
        max_propogate[root] = std::max({
            (root->left ? max_propogate[root->left] : -INT_MAX),
            (root->right ? max_propogate[root->right] : -INT_MAX),
            sum
        });

        int vl = (root->left ? max_propogate[root->left] - sum + root->val : -INT_MAX);
        int vr = (root->right ? max_propogate[root->right] - sum + root->val : -INT_MAX);

        result = std::max({
            result,
            root->val,
            vl,
            vr,
        }); 
        if(vl != -INT_MAX && vr != -INT_MAX)
            result = std::max(result, vl + vr - root->val);
        // std::cout << root->val << " " << sum << " " << max_propogate[root->left] << " " <<  max_propogate[root->right] << " " << result << "\n";
    }

public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return result;
    }
};
