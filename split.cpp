#include<bits/stdc++.h>
using namespace std;


int split(string &str){
  int mx=0;
  int freq[26]={};
  for(auto c:str){
    freq[c-'a']++;
  }
  int mx2=0;
  for(int i=0;i<26;i++){
    if(freq[i]){
      mx2++;
    }
  }
  int mx1=0;
  int taken[26]{};
  for(int p=0;p<str.length();p++){
    if(taken[str[p]-'a']==0){
      mx1++;
      taken[str[p]-'a']++;
    }
    freq[str[p]-'a']--;
    if(freq[str[p]-'a']==0){
      mx2--;
    }
    mx=max(mx,mx1+mx2);
  }
  return mx;
}

int main(){

  int tc;
  cin>>tc;

  while(tc>0){
    tc--;
    int n;
    cin>>n;
    string str;
    cin>>str;

    cout<<split(str)<<endl;
  }
}