#include<bits/stdc++.h>
using namespace std;

// int sumdigit(int n){
//   int sum=0;
//   while(n>0){
//     sum+=(n%10);
//     n/=10;
//   }
//   return sum;
// }

// int main(){

//   int tc;
//   cin>>tc;

//   unordered_map<int,int> mp;//num->sum
//   while(tc>0){
//     tc--;
//     int n,q;
//     cin>>n>>q;

//     vector<int> nums(n,0);
//     for(int i=0;i<n;i++){
//       cin>>nums[i];
//     }


//     while(q>0){
//       q--;
//       int type;
//       cin>>type;
//       if(type==1){
//         int l,r;
//         cin>>l>>r;
//         l--;
//         r--;
//         for(int i=l;i<=r;i++){
//           nums[i]= nums[i]<10 ? nums[i] : (mp[nums[i]]>0 ? mp[nums[i]] : (mp[nums[i]]= sumdigit(nums[i])));
//         }
//       }else{
//         int x;
//         cin>>x;
//         cout<<nums[x-1]<<endl;
//       }
//     }
//   }
// }

//////////////////

// int sumdigit(int n,int rounds){
//   if(rounds==0 || n<10){
//     return n;
//   }
//   int sum=0;
//   while(n>0){
//     sum+=(n%10);
//     n/=10;
//   }
//   return sumdigit(sum,rounds-1);
// }

int sumdigit(int n,int rounds){
  int sum=0;
  while(rounds>0){
    rounds--;
    while(n>0){
      sum+=(n%10);
      n/=10;
    }
    if(sum>=10){
      if(rounds>0){
        n=sum;
        sum=0;
      }else{
        return sum;
      }
    }else{
      return sum;
    }
  }
    return n;
}
int main(){
  int tc;
  cin>>tc;

  unordered_map<int,int> mp;//num->sum
  while(tc>0){
    tc--;
    int n,q;
    cin>>n>>q;

    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
      cin>>nums[i];
    }

    int qFreq[n]{};
    while(q>0){
      q--;
      int type;
      cin>>type;
      if(type==1){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        for(int i=l;i<=r;i++){
          qFreq[i]++;
        }
      }else{
        int x;
        cin>>x;
        x--;
        nums[x]=sumdigit(nums[x],qFreq[x]);
        qFreq[x]=0;
        cout<<nums[x]<<endl;
      }
    }
  }
}