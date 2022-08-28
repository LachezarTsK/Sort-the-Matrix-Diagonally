
import java.util.PriorityQueue;

public class Solution {

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
        PriorityQueue<Integer> values = new PriorityQueue<>();

        int r = row;
        int c = column;
        while (r < inputMatrix.length && c < inputMatrix[0].length) {
            values.offer(inputMatrix[r++][c++]);
        }

        r = row;
        c = column;
        while (r < inputMatrix.length && c < inputMatrix[0].length) {
            inputMatrix[r++][c++] = values.poll();
        }
    }
}
