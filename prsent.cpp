#include<bits/stdc++.h>
using namespace std;

int main(){

  int tc;
  cin>>tc;
  
  string str="codeforces";

  int pr[26]{};
  for(int i=0;i<str.length();i++){
    pr[str[i]-'a']++;
  }
  while(tc>0){
    tc--;
    char c;
    cin>>c;

    bool ans=pr[c-'a'];
    cout<<(ans  ? "YES" : "NO")<<endl;
  }

  return 0;
}