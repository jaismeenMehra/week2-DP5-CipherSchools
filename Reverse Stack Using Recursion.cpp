void insertBottomStack(stack<int> &stack,int x) {
    if (stack.empty()) {
        stack.push(x);
        return;
    }
    int tmp=stack.top();
    stack.pop();
    insertBottomStack(stack,x);
    stack.push(tmp);
}
void reverseStack(stack<int> &stack) {
  if (stack.empty()) {
      return;
  }
    int tmp=stack.top();
    stack.pop();
    reverseStack(stack);
    insertBottomStack(stack,tmp);
}