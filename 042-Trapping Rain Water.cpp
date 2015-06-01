int trap(int A[], int n) {  
        // Note: The Solution object is instantiated only once.  
        if(A==NULL || n<1)return 0;  
        int highest = A[0];  
        for(int i=1;i<n;i++)  
            if(A[i]>highest)highest=A[i];  
        int ** matrix = new int*[highest];  
        for(int i=0;i<highest;i++)  
        {  
            matrix[i]=new int[n];  
            memset(matrix[i],0,sizeof(int)*n);  
        }  
        for(int i = 0; i < n; i++)  
            for(int j = 1; j <= A[i]; j++)  
                matrix[highest-j][i]=1;  
          
        int water = 0;  
        int left = -1;  
        for(int i = 0; i < highest; i++)  
        {  
            left = -1;  
            for(int j = 0; j < n; j++)  
            {  
                if(matrix[i][j]==1)  
                {  
                    if(left==-1)  
                        left = j;  
                    else  
                    {  
                        water += j-left-1;  
                        left = j;  
                    }  
                }  
            }  
        }  
        for(int i=0;i<highest;i++)  
            delete[] matrix[i];  
        delete[] matrix;  
        return water;  
    }  
