#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &nums, int n)
{
    vector<int> nextSm(n,-1);
    int fill=n-1;
    stack<int> stck;
    for (int i = n - 1; i >= 0; i--) {
      while (!stck.empty() && stck.top() >= nums[i]) {
          stck.pop();
      }
      if(!stck.empty()){
          nextSm[fill]=stck.top();
      }
      stck.push(nums[i]);
      fill--;
    }
    return nextSm;
}