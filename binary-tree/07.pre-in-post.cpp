// All traversals, in one code

void All_in_one_traversal(node* root)
{
    if(root==nullptr)
      return;

    stack<pair<node*,int>> s;
    vector<int> pre, post,in;
    s.push({root,1}); // Push Root Element with Count = 1
                      //
    while(!s.empty())
    {
        auto it = s.top();

        if(it.second==1)      // PREORDER
        {
            pre.push_back(it.first->data);
            s.top().second = 2;
            if(it.first->left != nullptr)
                s.push({it.first->left,1});
        }

        else if(it.second==2) // INORDER
        {
            in.push_back(it.first->data);
            s.top().second = 3;
            if(it.first->right != nullptr)
              s.push({it.first->right,1});
        }

        else if(it.second==3)  // POSTORDER
        {
            post.push_back(it.first->data);
            s.pop();
        }
    }
}
