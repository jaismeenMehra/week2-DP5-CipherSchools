#include<bits/stdc++.h>
using namespace std;


int maxSum(vector<int> &nums,int n){
  int i=0,j=0;
  while(i<n){
    while(i<n && nums[i]>0){i++;}
    j=i+1;
    if(i>=n){//all processed
      break;
    }
    if(i==n-1){//last neg
      if(nums[i-1]<abs(nums[i])){
        nums[i-1]=-nums[i-1];
        nums[i]=-nums[i];
      }
      break;
    }

    while(j<n && nums[j]<=0){j++;}
    int count=j-i;
    if(count&1){
      if(count==1){
        if(nums[j]<abs(nums[j-1])){
          if(nums[j-2]<abs(nums[j-1])){
              nums[j-2]=-nums[j-2];
              nums[j-1]=-nums[j-1];
          }else{
            nums[j]=-nums[j];
            nums[j-1]=-nums[j-1];
          }
        }
      }else{
        
      }
    }else{
        for(int k=i;k<j;k++){
          nums[i]=-nums[i];
        }
    }
    i=j+1;
  }
  return accumulate(nums.begin(),nums.end(),0);
}
int main(){
  int tc;
  cin>>tc;

  while(tc>0){
    tc--;
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0; i<n; i++){
      cin>>nums[i];
    }

    cout<<maxSum(nums,n)<<endl;
  }
  return 0;
}