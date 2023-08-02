vector<vector<int>> Paths(Node* root)
{
    vector<vector<int>> ans;
    
    if(root == NULL) return ans;
    
    vector<int> temp;
    getPath(root, temp, ans);
    return ans;
}

bool isLeaf(Node* root) {
    if(!root -> left && !root -> right) return true;
    
    return false;
}

void getPath(Node* root, vector<int>& temp, vector<vector<int>>& ans) {
    if(root == NULL) return ;
    
    temp.push_back(root -> data);
    
    if(isLeaf(root)) ans.push_back(temp);
    
    getPath(root -> left, temp, ans);
    getPath(root -> right, temp, ans);
    
    // pop back the node, when its left and right subtree recursion is completed
    temp.pop_back();
}

