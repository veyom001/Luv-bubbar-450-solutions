stack<long long >st;
     vector<long long>result(n);
     result[n-1]=-1;
     st.push(arr[n-1]);
     for(int i=n-2;i>=0;i--)
     {
         while(!st.empty() && st.top()<=arr[i])
         {
             st.pop();
         }
         if(st.empty())
         {
             result[i]=-1;
         }
         else{
             result[i]=st.top();
         }
         st.push(arr[i]);
     }
     return result;
