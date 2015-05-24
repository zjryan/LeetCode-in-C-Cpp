class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    	vector<vector<int>> result;
    	int n = 0;
    	while (n < numRows){
    		vector<int> row(n + 1, 1);
    		if (n >= 2){
    			for (int i = 1; i < n; i++){
    				row[i] = result[n - 1][i - 1] + result[n - 1][i];
    			}
    		}
    		result.push_back(row);
    		n++;
    	}
    	return result;
    }
};
