vector<int> TopView(Node* root) {
  vector<int> ans;

  map<int, int> mp;
  queue<pair<Node*, int>> q;

  q.push({root, 0});

  while(!q.empty()) {
    auto a = q.front();
    q.pop();

    Node* temp = a.first;
    int line = a.second;

    if(mp.find(line) == mp.end()) {
      mp[line] = temp -> val;
    }

    if(temp -> left) q.push({temp -> left, line-1});
    if(temp -> right) q.push({temp -> right, line+1});
  }

  for(auto i : mp) {
    ans.push_back(i.second);
  }

  return ans;
}
