int celebrity(vector<vector<int> >& a, int n) 
    {
        // code here
       stack<int>st;
       for(int i=0;i<n;i++){
           st.push(i);
       }
       while(!st.empty()){
           if(st.size()==1)break;
           int x=st.top();st.pop();
           int y=st.top();st.pop();
           if(a[x][y])st.push(y);
           else if(a[y][x])st.push(x);
       }
       if(st.empty())return -1;
       int temp=st.top();
       for(int i=0;i<n;i++){
           if(a[temp][i])return -1;
           if(i!=temp && !a[i][temp])return -1;
       }
       return temp;
    }
