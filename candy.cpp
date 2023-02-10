#include<bits/stdc++.h>
using namespace std;

int main(){

  int tc;
  cin>>tc;

  while(tc>0){
    tc--;

    int n;
    cin>>n;
    string moves;
    cin>>moves;

    int x=0;
    int y=0;
    bool found = false;
    for(int i=0; i<n;i++){
      if(moves[i]=='L'){
          x--;
      }else if(moves[i]=='R'){
        x++;
      }else if(moves[i]=='U'){
        y++;
      }else{
        y--;
      }
      if(x==1 && y==1){
        cout<<"YES"<<endl;
        found=true;
        break;
      }
    }
    if(!found)
      cout<<"NO"<<endl;
  }
  return 0;
}  