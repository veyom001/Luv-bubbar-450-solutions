long long getMaxArea(long long arr[], int n)
    {
        // Your code here
       arr[n] = 0;
       stack<int> st;
       st.push(-1);
       long long ans = 0;
       for(int i=0;i<=n;i++){
           while(st.size()>1 && arr[st.top()]>=arr[i]){
               int ind = st.top();
               st.pop();
               ans = max(ans,arr[ind]*(i-st.top()-1));
           }
           st.push(i);
       }
       return ans;
   
    }
