class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        if(root == NULL)
            return 0;
        
        queue<pair<TreeNode* , int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            int first, last;
            
            int size = q.size();
            // as the first node will have the min index for every level
            int prev_level_min_index = q.front().second;
                        
            for(int i = 0; i < size; i++) {
                long long curr_index = q.front().second - prev_level_min_index;
                
                TreeNode* current = q.front().first;
                q.pop();
                
                if(i == 0)
                    first = curr_index;
                if(i == size - 1)
                    last = curr_index;
                
                if(current -> left)
                    q.push({current -> left, (curr_index*2 + 1)});
                if(current -> right)
                    q.push({current -> right, (curr_index*2 + 2)});
            }
            
            ans = max(ans, last - first + 1);
        }
        
        return ans;
    }
};
