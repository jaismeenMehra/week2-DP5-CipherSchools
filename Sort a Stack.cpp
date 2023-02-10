#include <bits/stdc++.h> 
using namespace std;

void insertAtRightPlace(stack<int> &stck,int x) {
  if (stck.empty() || stck.top()<x) {
	  stck.push(x);
		return;
  }
  int tmp=stck.top();
  stck.pop();
  insertAtRightPlace(stck,x);
  stck.push(tmp);
}

void sortStack(stack<int> &stck){
  if (stck.empty()) {
	  return;
  }
    int tmp=stck.top();
	stck.pop();
	sortStack(stck);
	insertAtRightPlace(stck,tmp);
}