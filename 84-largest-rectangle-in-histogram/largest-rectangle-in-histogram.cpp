class Solution {
public:
    void nextSmaller(vector<int>&heights,vector<int>&nextAns){
        stack<int>st;
        st.push(-1);
        int n=heights.size();
        for(int i=n-1;i>=0;i--){
            int elements=heights[i];
            while(st.top()!=-1&&heights[st.top()]>=elements){
                st.pop();
            }
            nextAns.push_back(st.top());
            st.push(i);

        }
    }  

    void prevSmaller(vector<int>&heights,vector<int>&prevAns){
        stack<int>st;
        st.push(-1);
        int n=heights.size();
        for(int i=0;i<n;i++){
            int elements=heights[i];
            while(st.top()!=-1&&heights[st.top()]>=elements){
                st.pop();
            }
            prevAns.push_back(st.top());
            st.push(i);

        }
    } 
    int largestRectangleArea(vector<int>& heights) {
        vector<int>nextAns;
        vector<int>prevAns;
        nextSmaller(heights,nextAns);
        reverse(nextAns.begin(),nextAns.end());
        prevSmaller(heights,prevAns);
        for(int i=0;i<nextAns.size();i++){
            if(nextAns[i]==-1){
                nextAns[i]=nextAns.size();
            }

        }
        int maxAns=INT_MIN;
        for(int j=0;j<nextAns.size();j++){
            int width=nextAns[j]-prevAns[j]-1;
            int height=heights[j];
            int area=width*height;
            maxAns=max(maxAns,area);
        }
        return maxAns;
        
    }
};