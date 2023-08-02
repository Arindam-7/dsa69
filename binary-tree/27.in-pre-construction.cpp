// map can not be used for the sake of O(1) time, because of presence of duplicate node value

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

class Solution {
public:
    int find(vector<int>& inorder, int inStart, int inEnd, int elem, int n) {
        for(int i = inStart; i <= inEnd; i++) {
            if(inorder[i] == elem) return i;
        }
        return -1;
    }

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& preOrderIndex, int inStart, int inEnd, int size) {
        if(inStart > inEnd) return NULL;

        int elem = preorder[preOrderIndex];
        preOrderIndex++;
        int position = find(inorder, inStart, inEnd, elem, size);
        TreeNode* root = new TreeNode(elem);

        root->left = solve(preorder, inorder, preOrderIndex, inStart, position-1, size);
        root->right = solve(preorder, inorder, preOrderIndex, position+1, inEnd, size);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;
        int n = inorder.size();
        return solve(preorder, inorder, preOrderIndex, 0, n-1, n);
    }
};
