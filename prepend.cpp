#include<bits/stdc++.h>
using namespace std;

int main(){

  int tc;
  cin>>tc;

  while(tc>0){
    tc--;

    int n;
    cin>>n;

    string timur;
    cin>>timur;

    int i=0;
    int j=n-1;
    while(i<j){
      if(timur[i]!=timur[j]){
        i++;
        j--;
      }else{
        break;
      }
    }
    cout<<(i>j ? 0 : j-i+1)<<endl;
  }

  return 0;
}