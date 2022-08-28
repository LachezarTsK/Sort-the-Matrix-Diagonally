
public class Solution {

    private static final int[] RANGE_VALUES = {1, 100};

    public int[][] diagonalSort(int[][] inputMatrix) {

        for (int row = 0; row < inputMatrix.length; ++row) {
            sortDiagonal(inputMatrix, row, 0);
        }
        for (int column = 1; column < inputMatrix[0].length; ++column) {
            sortDiagonal(inputMatrix, 0, column);
        }
        return inputMatrix;
    }

    private void sortDiagonal(int[][] inputMatrix, int row, int column) {
        int[] frequency = new int[RANGE_VALUES[1] + 1];

        int r = row;
        int c = column;
        while (r < inputMatrix.length && c < inputMatrix[0].length) {
            ++frequency[inputMatrix[r++][c++]];
        }

        r = row;
        c = column;
        for (int value = 0; value < frequency.length; ++value) {
            while (frequency[value]-- > 0) {
                inputMatrix[r++][c++] = value;
            }
        }
    }
}
