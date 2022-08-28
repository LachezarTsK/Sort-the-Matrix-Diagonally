
/**
 * @param {number[][]} inputMatrix
 * @return {number[][]}
 */
var diagonalSort = function (inputMatrix) {
    this.RANGE_VALUES = [1, 100];

    for (let row = 0; row < inputMatrix.length; ++row) {
        sortDiagonal(inputMatrix, row, 0);
    }
    for (let column = 1; column < inputMatrix[0].length; ++column) {
        sortDiagonal(inputMatrix, 0, column);
    }
    return inputMatrix;
};

/**
 * @param {number[][]} inputMatrix
 * @param {number} row
 * @param {number} column
 * @return {void}
 */
function sortDiagonal(inputMatrix, row, column) {
    const frequency = new Array(this.RANGE_VALUES[1] + 1).fill(0);

    let r = row;
    let c = column;
    while (r < inputMatrix.length && c < inputMatrix[0].length) {
        ++frequency[inputMatrix[r++][c++]];
    }

    r = row;
    c = column;
    for (let value = 0; value < frequency.length; ++value) {
        while (frequency[value]-- > 0) {
            inputMatrix[r++][c++] = value;
        }
    }
}
