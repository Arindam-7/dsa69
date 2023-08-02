vector<int> BottomView(Node* root) {
  vector<int> ans;

  map<int, int> mp;
  queue<pair<Node*, int>> q;

  q.push({root, 0});

  while(!q.empty()) {
    auto a = q.front();
    q.pop();

    Node* temp = a.first;
    int line = a.second;

    // first value of line 0 will be replaced by consecutive values of line 0, thus will end up with the recent (bottom) value only
    mp[line] = temp -> val;

    if(temp -> left) q.push({temp -> left, line-1});
    if(temp -> right) q.push({temp -> right, line+1});
  }

  for(auto i : mp) {
    ans.push_back(i.second);
  }

  return ans;
}

