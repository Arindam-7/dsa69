// https://practice.geeksforgeeks.org/problems/binary-tree-representation/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=binary-tree-representation

class Solution{
public:

    void create_tree(node* root0, vector<int> &vec){
        int n = vec.size();
        queue<struct node* > q;
        q.push(root0);
        
        for(int i = 0; i < n/2; i++) {
            int left = 2*i+1;
            int right = 2*i+2;
            
            struct node* temp = q.front();
            q.pop();
            
            if(left < n) temp -> left = newNode(vec[left]);
            if(right < n) temp -> right = newNode(vec[right]);
            
            q.push(temp -> left);
            q.push(temp -> right);
        }
    }

};

