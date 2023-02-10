#include<bitset/stdc++.h>
using namespace std;

int main(){
  string s="aabbaabbaabbaabb";

  int fr[26]{};
  for(int i=0; i<s.length(); i++){
    fr[s[i]-'a']++;
  }

  int mn=INT_MAX;
  for(int i=1; i<26; i++){
    if(fr[i]>0){
      if(mn!=INT_MAX && fr[i]!=mn){
        return false;
      }
      mn=fr[i];
    }
  }
  return mn==1 ? false : true;
}