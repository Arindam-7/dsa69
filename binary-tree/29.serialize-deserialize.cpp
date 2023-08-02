// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      if(root == NULL) return "";

      string ans = "";
      queue<TreeNode* > q;
      q.push(root);

      while(!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        if(temp == NULL) ans.append("#,");
        else ans.append(to_string(temp -> val) + ",");

        if(temp != NULL) {
          q.push(temp -> left);
          q.push(temp -> right);
        }
      }
      cout << ans;
      return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) { 
      if(data.length() == 0) return NULL;

      stringstream s(data);
      string str;
      getline(s, str, ',');

      TreeNode* root = new TreeNode(stoi(str));

      queue<TreeNode* > q;
      q.push(root);

      while(!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        getline(s, str, ',');

        if(str == "#") temp -> left = NULL;
        else {
          TreeNode* leftNode = new TreeNode(stoi(str));
          temp -> left = leftNode;
          q.push(leftNode);
        }

        getline(s, str, ',');

        if(str == "#") temp -> right = NULL;
        else {
          TreeNode* rightNode = new TreeNode(stoi(str));
          temp -> right = rightNode;
          q.push(rightNode);
        }
      }

      return root;
    }
};
