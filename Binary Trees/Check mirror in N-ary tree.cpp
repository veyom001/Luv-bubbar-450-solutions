int checkMirrorTree(int n, int e, int A[], int B[]) {
       
        map<int,stack<int>>helper;
        for(int i=0;i<2*e;i+=2)
        {
            helper[A[i]].push(A[i+1]);
        }
        
        for(int i=0;i<2*e;i+=2)
        {
            if(helper[B[i]].top()!=B[i+1])
            return false;
            
            helper[B[i]].pop();
            
        }
        return true;
        
    }