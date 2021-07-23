#!/usr/bin/python3
"""N queens puzzle is the challenge of placing N non-attacking queens
on an N×N chessboard
"""
import sys


def print_solution(board):
    """print the coordinates row and column for the position of
       each N queen in the posible solution
    Arg:
       - board: matrix[n][n], list of list
    """
    queens_placed = []
    for i in range(len(board)):
        for j in range(len(board)):
            if board[i][j] == 1:
                queens_placed.append([i, j])
    print(queens_placed)


def safe_move(board, row, col, n):
    """check if queen move is safe in board[row][col] index
    Arg:
       - board: matrix[n][n], list of list
       - row: index i to check
       - col: index j to check
       - n: number of queens to placed
    Return: True or False
       - True: if the queen coulb be placed, save place
       - False: if there is not a save place
    """
    for i in range(col):
        if board[row][i] == 1:
            return False
    for i, j in zip(range(row, -1, -1),
                    range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    for i, j in zip(range(row, n, 1),
                    range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    return True


def n_queens(board, col, n):
    """n queens puzzle using Backtracking
    Arg:
       - board: list of list, of size board[n][n], n number of queens
       - col: starts to check since column 0 until n to placed
              one queebn per position
       - n: number of queens to be placed
    Return:
       - True: if all the queens are placed on the board
       - False: if a queen can not be placed
    """
    if col == n:
        print_solution(board)
        return True

    total_q = False
    for row in range(n):
        if safe_move(board, row, col, n):
            board[row][col] = 1
            total_q = n_queens(board, col + 1, n) or total_q
            board[row][col] = 0
    return total_q

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    if sys.argv[1].isdigit() is False:
        print("N must be a number")
        exit(1)
    n = int(sys.argv[1])
    if n < 4:
        print("N must be at least 4")
        exit(1)

    board = [[0 for i in range(n)] for j in range(n)]
    n_queens(board, 0, n)
