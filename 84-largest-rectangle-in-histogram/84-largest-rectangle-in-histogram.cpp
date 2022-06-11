class Solution {
public:
    int largestRectangleArea(vector<int>& histo) {
//         int n = heights.size();
//         int leftSmall[n],rightSmall[n];
//         stack<int>st;
        
//         //search for left small
//         for(int i=0;i<n;i++){
//             while(!st.empty() && heights[i]<=heights[st.top()] ){
//                 st.pop();
//             }
//             if(st.empty())
//                 leftSmall[i] = 0;
//             else
//                 leftSmall[i] = st.top()+1; 
//             st.push(i);
//         }
//         //making the stack empty to use it again
//         while(!st.empty()){
//             st.pop();
//         }
        
//          for(int i=n-1;i>=0;i--){
//             while(!st.empty() && heights[i]<=heights[st.top()] ){
//                 st.pop();
//             }
//             if(st.empty())
//                 rightSmall[i] = n-1;
//             else
//                 rightSmall[i] = st.top()-1; 
//             st.push(i);
//         }
//         int largestArea=0;
//         for(int i=0;i<n;i++){
//             largestArea = max(largestArea, (rightSmall[i] - leftSmall[i] + 1)*heights[i]);
//         }
//         return largestArea;
        // 2nd approach
        stack<int>st;
        int maxA=0;
        int n = histo.size();
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || histo[st.top()]>=histo[i])){
                int height = histo[st.top()];
                st.pop();
                int width;
                if(st.empty()) width = i;
                else width = i- st.top() - 1;
                maxA = max(maxA, width*height);
            }
            st.push(i);
        }
        return maxA;
    }
};