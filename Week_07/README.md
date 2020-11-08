学习笔记
单词搜索时间复杂度：board的遍历n2乘以+words的长度和单词的最大长度的乘，n2+km，k为单词最大长度，m为单词数组长度，n为board单维长度。
双向BFS模版：
// C/C++
void bfs(vecot<Node*> noteVec) {
  map<int, int> visited;
  if(noteVec.size() < 1) return ;

  queue<Node*>* queueFrontNode = new queue<Node*>();  
  queue<Node*>* queueBackNode = new queue<Node*>)();    
  unoredered_set<int>* visitedFront = new unoredered_set<int>();  
  unoredered_set<int>* visitedBack = new unoredered_set<int>(); 
  queue<Node*>* queueBackNode = new queue<Node*>)()
  queueFrontNode.push(noteVec.front());
  queueBackNode.push(noteVec.back());

  while (!queueFrontNode.empty() && !queueBackNode.empty()) {
    if (queueFrontNode.size() > queueBackNode.size()) {
      swap(queueFrontNode, queueBackNode);
      swap(visitedFront, visitedBack);
    }
    Node* node = queueFrontNode.top();
    queueFrontNode.pop();
    if (visitedFront.count(node->val)) continue;
    visitedFront[node->val] = 1;

    for (int i = 0; i < node->children.size(); ++i) {
        queueFrontNode.push(node->children[i]);
    }
  }

  return ;
}