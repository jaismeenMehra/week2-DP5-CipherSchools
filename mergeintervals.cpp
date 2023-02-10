class Comparator{
public:
    bool operator ()(const vector<int> &a,const vector<int> &b)const{
        return a[0]<b[0];
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),Comparator());
        stack<vector<int>> stck;
        for(int i=0;i<intervals.size();i++){
            if(stck.empty()){
                stck.push(intervals[i]);
            }else{
                vector<int> &tp=stck.top();
                if(tp[0]<=intervals[i][0] && tp[1]>=intervals[i][1]){//total inside the previous
                    continue;
                }else if(tp[1]>=intervals[i][0] && tp[1]<intervals[i][1]){//ahead of previous one
                    int common=tp[1]-intervals[i][0];
                    tp[1]=tp[1]+(intervals[i][1]-intervals[i][0])-common;
                }else{
                    stck.push(intervals[i]);
                }
            }
        }
        int stckLen=stck.size();
        vector<vector<int>> res(stckLen);
        for(int i=stckLen-1;i>=0;i--){
            res[i]=stck.top();
            stck.pop();
        }
        return res;
    }
};