#include <bits/stdc++.h> 
stack<int> pushAtBottom(stack<int>& myStack, int x) {
    stack<int> stck;
    while (!myStack.empty()) {
        stck.push(myStack.top());
        myStack.pop();
    }
    myStack.push(x);
    while (!stck.empty()) {
        myStack.push(stck.top());
        stck.pop();
    }
    return myStack;
}
