
#include <queue>
#include <vector>
#include <functional>
using namespace std;

class Solution {
    
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& inputMatrix) {
        for (int row = 0; row < inputMatrix.size(); ++row) {
            sortDiagonal(inputMatrix, row, 0);
        }
        for (int column = 1; column < inputMatrix[0].size(); ++column) {
            sortDiagonal(inputMatrix, 0, column);
        }
        return inputMatrix;
    }
    
private:
    void sortDiagonal(vector<vector<int>>& inputMatrix, int row, int column) {

        // greater<> instead of greater<int>
        // it is recommended to apply a transparent operator for Standard Library containers that accept a comparator type.
        priority_queue<int, vector<int>, greater<>> values;

        int r = row;
        int c = column;
        while (r < inputMatrix.size() && c < inputMatrix[0].size()) {
            values.push(inputMatrix[r++][c++]);
        }

        r = row;
        c = column;
        while (r < inputMatrix.size() && c < inputMatrix[0].size()) {
            inputMatrix[r++][c++] = values.top();
            values.pop();
        }
    }
};
