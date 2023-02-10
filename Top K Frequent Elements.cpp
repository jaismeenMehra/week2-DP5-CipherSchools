class Comparator{
public:
    bool operator()(const pair<int,int> &p1,const pair<int,int> &p2){
        return p1.second>p2.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(const int &num:nums){
            mp[num]++;
        }
        vector<pair<int,int>> freq(mp.begin(),mp.end());
        sort(freq.begin(),freq.end(),Comparator());
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(freq[i].first);
        }
        return ans;
    }
};