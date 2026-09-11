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

class Codec {
private:
    int traverse(TreeNode* v, std::string& result)
    {
        int left_offset = (v->left ? traverse(v->left, result) : -1);
        int right_offset = (v->right ? traverse(v->right, result) : -1);

        result += to_string(v->val);
        result += '*';  
        result += to_string(left_offset);
        result += '*';
        result += to_string(right_offset);
        result += '#';

        return result.size() - 1;
    }

    // void output_tree(TreeNode* node)
    // {
    //     cout_node(node);
    //     if(node->left)
    //         output_tree(node->left);
    //     if(node->right)
    //         output_tree(node->right);
    // }

    // void cout_node(TreeNode* node)
    // {
    //     if(!node)
    //     {
    //         // std::cout << "nullptr\n";
    //         return;
    //     }
    //     std::cout << node->val << " " << (node->right ? node->right->val : -1) << " " << (node->left ? node->left->val : -1) << "\n";
    // }

public:


    // * seperator for node
    // # seperator between nodes
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "";

        std::string result;
        
        traverse(root, result);
        
        // std::cout << result << "\n";
        return result;
    }
 
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::string buffer;
        std::unordered_map<int, TreeNode*> offset_to_node;
        int val, left_offset, right_offset, cnt = 0;

        TreeNode* last_created_node = nullptr;

        for(int i = 0; i < data.size(); i ++)
        {
            if(data[i] == '*')
            {
                // std::cout << buffer << " ";
                if(cnt == 0)
                    val = atoi(buffer.c_str());
                else if(cnt == 1)
                    left_offset = atoi(buffer.c_str());
                buffer = "";
                cnt ++;
            }
            else if(data[i] == '#')
            {
                // std::cout << buffer << "\n";

                right_offset = atoi(buffer.c_str());
                buffer = "";

                TreeNode* new_node = new TreeNode(
                    val,
                    (left_offset != -1 ? offset_to_node[left_offset] : nullptr),
                    (right_offset != -1 ? offset_to_node[right_offset] : nullptr)
                );
                offset_to_node[i] = new_node;

                cnt = 0;

                last_created_node = new_node;
            }
            else
                buffer += data[i];
        }

        return last_created_node;
    }
};
