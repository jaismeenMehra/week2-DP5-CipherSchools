class Solution {
vector<int> nextMin(vector<int>& heights,int n){
    stack<int> stck;
    vector<int> nxtmn(n,n);
    for(int i=n-1;i>=0;i--){
        while(!stck.empty() && heights[stck.top()]>=heights[i]){
            stck.pop();
        }
        if(!stck.empty()){
            nxtmn[i]=stck.top();
        }
        stck.push(i);
    }
    return nxtmn;
}
vector<int> prevMin(vector<int>& heights,int n){
    stack<int> stck;
    vector<int> prvmn(n,-1);
    for(int i=0;i<n;i++){
        while(!stck.empty() && heights[stck.top()]>=heights[i]){
            stck.pop();
        }
        if(!stck.empty()){
            prvmn[i]=stck.top();
        }
        stck.push(i);
    }

    return prvmn;
}
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nm=nextMin(heights,n);
        vector<int> pm=prevMin(heights,n);

        int mxArea=INT_MIN;
        for(int i=0;i<n;i++){
            mxArea=max(mxArea,heights[i]*(nm[i]-pm[i]-1));
        }
        return mxArea;
    }
};