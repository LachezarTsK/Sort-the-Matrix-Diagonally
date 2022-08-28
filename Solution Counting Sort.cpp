
#include <array>
#include <vector>
using namespace std;

class Solution {
    
    static constexpr array<int, 2> RANGE_VALUES {1, 100};

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
        array<int, RANGE_VALUES[1] + 1 > frequency{};

        int r = row;
        int c = column;
        while (r < inputMatrix.size() && c < inputMatrix[0].size()) {
            ++frequency[inputMatrix[r++][c++]];
        }

        r = row;
        c = column;
        for (int value = 0; value < frequency.size(); ++value) {
            while (frequency[value]-- > 0) {
                inputMatrix[r++][c++] = value;
            }
        }
    }
};
