// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

class Solution {
public:
    int find(vector<int>& inorder, int inStart, int inEnd, int elem, int n) {
        for(int i = inStart; i <= inEnd; i++) {
            if(inorder[i] == elem) return i;
        }
        return -1;
    }

    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int& postOrderIndex, int inStart, int inEnd, int size) {
        if(inStart > inEnd) return NULL;

        int elem = postorder[postOrderIndex];
        postOrderIndex--;
        int position = find(inorder, inStart, inEnd, elem, size);
        TreeNode* root = new TreeNode(elem);

        root->right = solve(postorder, inorder, postOrderIndex, position+1, inEnd, size);
        root->left = solve(postorder, inorder, postOrderIndex, inStart, position-1, size);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int postOrderIndex = n-1;
        return solve(postorder, inorder, postOrderIndex, 0, n-1, n);
    }
};
