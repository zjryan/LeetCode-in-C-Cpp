class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> level; 
        for(int i = 0;i <= rowIndex;i++)  
        {  
            int k = (int)level.size();  
            for(int j = k - 1; j >= 1; j--)  
                level[j] += level[j-1];  
            level.push_back(1);  
        }  
        return level;          
    }
};
