int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;
        int n = S.length();
        for(int i=0; i<n; i++)
        {
           
            if(isdigit(S[i]))
            {
                st.push(S[i]-'0');
            }
            else
            {
                int A = st.top();
                    st.pop();
                int B = st.top();
                    st.pop();
                
                switch(S[i])
                {
                    case '+': st.push(B+A);
                    break;
                    case '-': st.push(B-A);
                    break;
                    case '*': st.push(B*A);
                    break;
                    case '/': st.push(B/A);
                    break;
                }
            }
        }
        return st.top();
    }
