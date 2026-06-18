class Solution {
public:
    void nextSmaller(vector<int>&arr,vector<int>&ans){
        stack<int>st;
        st.push(-1);
        
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty()&&st.top()!=-1&&arr[st.top()]>arr[i]) st.pop();
            ans.push_back(st.top());
            st.push(i);
        }

    }
    void prevSmaller(vector<int>&arr,vector<int>&ans){
        stack<int>st;
        st.push(-1);
        
        for(int i=0;i<arr.size();i++){
            while(!st.empty()&&st.top()!=-1&&arr[st.top()]>=arr[i]) st.pop();
            ans.push_back(st.top());
            st.push(i);
        }

    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>next;
        vector<int>prev;
        nextSmaller(arr,next);
        reverse(next.begin(),next.end());
        prevSmaller(arr,prev);
        long long int sum=0;
        int mod=1e9+7;
        for(int i=0;i<arr.size();i++){
            int nexti=next[i]==-1?next.size():next[i];
            int previ=prev[i];
            int left=i-previ;
            int right=nexti-i;
            long long int a=(left*right)%mod;
            long long int b=(arr[i]*a)%mod;
            sum=(sum+b)%mod;
        }

        return sum;
        
    }
};