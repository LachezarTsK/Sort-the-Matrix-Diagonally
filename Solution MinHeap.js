
/**
 * @param {number[][]} inputMatrix
 * @return {number[][]}
 */
var diagonalSort = function (inputMatrix) {
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
    const {PriorityQueue} = require('@datastructures-js/priority-queue');
    const values = new MinPriorityQueue({compare: (x, y) => x - y});

    let r = row;
    let c = column;
    while (r < inputMatrix.length && c < inputMatrix[0].length) {
        values.enqueue(inputMatrix[r++][c++]);
    }

    r = row;
    c = column;
    while (r < inputMatrix.length && c < inputMatrix[0].length) {
        inputMatrix[r++][c++] = values.dequeue();
    }
}
