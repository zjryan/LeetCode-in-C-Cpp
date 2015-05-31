class Solution {
public:
    static int min (int x, int y){
        return x < y ? x : y;
    }
    int minimumTotal(vector<vector<int> > &triangle){
        size_t row = triangle.size();
        if (row == 0) {
            return 0;
        }
        vector<vector<int> > auxTriangle;
        auxTriangle.push_back(triangle.at(0));
        for(auto i = 1; i< row; i++){
            vector<int> rowVec(i + 1, 0);
            auxTriangle.push_back(rowVec);
            *auxTriangle.at(i).begin() = *auxTriangle.at(i-1).begin() + *triangle.at(i).begin();
            *--auxTriangle.at(i).end() =  *--auxTriangle.at(i-1).end() + *--triangle.at(i).end();
        }
        for (auto i = 0; i < row; i++) {
            auto rowSize = auxTriangle.at(i).size();
            for (auto j = 1; j < rowSize - 1; j++) {
                auxTriangle.at(i).at(j) = min(auxTriangle.at(i-1).at(j-1), auxTriangle.at(i-1).at(j))
                                            +triangle.at(i).at(j);
            }
        }
        int minSum = auxTriangle.at(row - 1).at(0);
    	for (int i : auxTriangle.at(row - 1)){
    		if (minSum > i) minSum = i;
    	}
        return minSum;
    }
};
