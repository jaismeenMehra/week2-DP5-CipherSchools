class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //All integers in nums1 and nums2 are unique.
        int lens2=nums2.size();
        int lens1=nums1.size();
        
        stack<int> stck; //similar to no of visible people in queue.cpp
        map<int,int> nxtG;
        for(int i=lens2-1;i>=0;i--){
            while(!stck.empty() && stck.top()<nums2[i]){
                stck.pop();
            }
            if(stck.empty()){
                nxtG[nums2[i]]=-1;
            }else{
                nxtG[nums2[i]]=stck.top();
            }
            stck.push(nums2[i]);
        }

        vector<int> res(lens1,0);
        for(int i=0;i<lens1;i++){
            res[i]=nxtG[nums1[i]];
        }
        return res;
    }
};