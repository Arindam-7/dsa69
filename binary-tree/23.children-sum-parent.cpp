// https://practice.geeksforgeeks.org/problems/children-sum-parent/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=hildren-sum-parent

class Solution{
    public:
    void sum(Node* root, int child, int& ans) {
        if(ans == 0 || root == NULL || (root -> left == NULL && root -> right == NULL)) return;
        
        if(root -> left) child += root -> left -> data;
        if(root -> right) child += root -> right -> data;
        
        if(root -> data != child) {
            ans = 0;
            return;
        }
        
        sum(root -> left, 0, ans);
        sum(root -> right, 0, ans);
    }
    
    int isSumProperty(Node *root)
    {
        int ans = 1;
        sum(root, 0, ans);
        return ans;
    }
};
